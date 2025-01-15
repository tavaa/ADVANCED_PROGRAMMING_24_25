import os
import sys
from typing import List, Union, Optional, Any
from .Cell import Cell

# Add the build directory to the system path to import the C++ bindings
build_dir = os.path.abspath("../../build/src/")
sys.path.append(build_dir)

from scientific_toolbox import CSVParser as CppCSVParser

class CSVParser:
    """
    A Python wrapper for the C++ CSVParser class, extending its functionality with Python-specific features.

    Attributes:
        headers (Optional[List[str]]): Stores the CSV headers if available.
        data (List[List[Cell]]): Parsed CSV data stored as a list of lists of `Cell` objects.
    """

    def __init__(self, file_path: str, delimiter: str = ',', has_headers: bool = True):
        """
        Initializes the CSVParser instance with the specified file path and parsing settings.

        Args:
            file_path (str): Path to the CSV file to be parsed.
            delimiter (str): Character used to separate fields in the CSV file. Defaults to ','.
            has_headers (bool): Indicates if the CSV file contains a header row. Defaults to True.
        """
        self._cpp_parser = CppCSVParser.CSVParser(file_path, delimiter, has_headers)
        self.headers = None
        self.data: List[List[Cell]] = []

        # Parse the CSV file upon initialization
        cpp_data = self._cpp_parser.parse()
        self.data = [[Cell(cell) for cell in row] for row in cpp_data]
        self.headers = self._cpp_parser.getHeaders()

    '''
    def parse(self):
        """
        Parses the CSV file using the underlying C++ CSVParser and stores the data as Python objects.

        Postconditions:
            - `self.data` contains the parsed rows as lists of `Cell` objects.
            - `self.headers` is populated if the CSV file has headers.
        """
        cpp_data = self._cpp_parser.parse()
        self.data = [[Cell(cell) for cell in row] for row in cpp_data]
        self.headers = self._cpp_parser.getHeaders()
    '''

    def get_headers(self) -> Optional[List[str]]:
        """
        Retrieves the headers of the CSV file if they are available.

        Returns:
            Optional[List[str]]: The list of header strings if the CSV file has headers, otherwise None.
        """
        return self.headers

    def get_num_rows(self) -> int:
        """
        Retrieves the number of data rows in the CSV file (excluding the header row).

        Returns:
            int: The number of data rows in the CSV file.
        """
        return self._cpp_parser.getNumRows()

    def get_head(self, count: int) -> List[List[Cell]]:
        """
        Retrieves the first `count` rows of the dataset.

        Args:
            count (int): Number of rows to retrieve from the start of the dataset.

        Returns:
            List[List[Cell]]: A list of rows, where each row is a list of `Cell` objects.
        """
        cpp_head = self._cpp_parser.getHead(count)
        return [[Cell(cell) for cell in row] for row in cpp_head]

    def get_tail(self, count: int) -> List[List[Cell]]:
        """
        Retrieves the last `count` rows of the dataset.

        Args:
            count (int): Number of rows to retrieve from the end of the dataset.

        Returns:
            List[List[Cell]]: A list of rows, where each row is a list of `Cell` objects.
        """
        cpp_tail = self._cpp_parser.getTail(count)
        return [[Cell(cell) for cell in row] for row in cpp_tail]

    def get_row(self, index: int) -> Optional[List[Cell]]:
        """
        Retrieves a specific row from the dataset by its index.

        Args:
            index (int): The zero-based index of the row to retrieve.

        Returns:
            Optional[List[Cell]]: The requested row as a list of `Cell` objects, or None if the index is out of range.
        """
        cpp_row = self._cpp_parser.getRow(index)
        if cpp_row:
            return [Cell(cell) for cell in cpp_row]
        return None

    def get_column(self, column_name: str) -> List[Cell]:
        """
        Retrieves a specific column from the dataset by its name.

        Args:
            column_name (str): The name of the column to retrieve.

        Returns:
            List[Cell]: A list of `Cell` objects representing the column's values.

        Raises:
            KeyError: If the column name does not exist in the dataset.
        """
        if not self.headers or column_name not in self.headers:
            raise KeyError(f"Column '{column_name}' not found.")
        cpp_column = self._cpp_parser[column_name]
        return [Cell(cell) for cell in cpp_column]

    '''
    def to_csv(self, output_path: str):
        """
        Exports the parsed dataset to a new CSV file at the specified path.

        Args:
            output_path (str): The file path where the new CSV file will be saved.

        Postconditions:
            - A new CSV file is created at the specified path containing the data from this parser.
        """
        with open(output_path, mode='w', encoding='utf-8', newline='') as file:
            import csv
            writer = csv.writer(file, delimiter=self._cpp_parser.delimiter)
            if self.headers:
                writer.writerow(self.headers)
            writer.writerows([[cell.value for cell in row] for row in self.data])
    '''
    
    def __getitem__(self, column_name: str) -> List[Cell]:
        """
        Provides access to a column via the indexing operator.

        Args:
            column_name (str): The name of the column to access.

        Returns:
            List[Cell]: A list of `Cell` objects representing the column's values.
        """
        return self.get_column(column_name)

    def __repr__(self):
        """
        Returns a string representation of the CSVParser instance.

        Returns:
            str: A string summarizing the number of rows and headers in the dataset.
        """
        return (f"ExtendedCSVParser(rows={len(self.data)}, "
                f"headers={self.headers})")
