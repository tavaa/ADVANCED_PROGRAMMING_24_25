import os
import sys
from typing import List, Union, Optional, Any

# Add the build directory to the system path to import the C++ bindings
build_dir = os.path.abspath("../../build/src/")
sys.path.append(build_dir)

from scientific_toolbox import statistics as NativeStatistics

class Statistics:
    """
    A class to represent and perform statistical operations on a CSV data file.

    Attributes:
        _native_statistics: An instance of the `NativeStatistics` class
            that performs the actual statistical operations.
    """

    def __init__(self, file_path: str, delimiter: str = ",", has_headers: bool = True):
        """
        Initializes a Statistics instance with a CSV file for analysis.

        Args:
            file_path (str): The path to the CSV file.
            delimiter (str): The delimiter used in the CSV file (default is ',').
            has_headers (bool): Whether the CSV file contains headers (default is True).
        """
        self._native_statistics = NativeStatistics.Statistics(file_path, delimiter, has_headers)

    def get_headers(self) -> List[str]:
        """
        Retrieve the headers of the CSV file.

        Returns:
            List[str]: A list of column names in the CSV file.
        """
        return self._native_statistics.get_headers()

    def get_column(self, column_name: str) -> List[Any]:
        """
        Retrieve all values from a specified column in the CSV file.

        Args:
            column_name (str): The name of the column to retrieve.

        Returns:
            List[Any]: A list of values in the specified column.
        """
        return self._native_statistics.get_column(column_name)

    @classmethod
    def from_csv(cls, file_path: str, delimiter: str = ",", has_headers: bool = True) -> 'Statistics':
        """
        Alternate constructor to create a Statistics instance from a CSV file.

        Args:
            file_path (str): The path to the CSV file.
            delimiter (str): The delimiter used in the CSV file (default is ',').
            has_headers (bool): Whether the CSV file contains headers (default is True).

        Returns:
            Statistics: A new instance of the Statistics class.
        """
        return cls(file_path, delimiter, has_headers)

    @staticmethod
    def min_value(column_values: List[Union[int, float]]) -> Union[int, float]:
        """
        Calculate the minimum value from a list of column values.

        Args:
            column_values (List[Union[int, float]]): The list of values to analyze.

        Returns:
            Union[int, float]: The minimum value in the list.
        """
        return NativeStatistics.Statistics.min_value(column_values)

    @staticmethod
    def max_value(column_values: List[Union[int, float]]) -> Union[int, float]:
        """
        Calculate the maximum value from a list of column values.

        Args:
            column_values (List[Union[int, float]]): The list of values to analyze.

        Returns:
            Union[int, float]: The maximum value in the list.
        """
        return NativeStatistics.Statistics.max_value(column_values)

    @staticmethod
    def calculate_mean(column_values: List[Union[int, float]]) -> float:
        """
        Calculate the mean (average) of a list of column values.

        Args:
            column_values (List[Union[int, float]]): The list of values to analyze.

        Returns:
            float: The mean of the values in the list.
        """
        return NativeStatistics.Statistics.calculate_mean(column_values)

    @staticmethod
    def calculate_median(column_values: List[Union[int, float]]) -> Union[int, float]:
        """
        Calculate the median of a list of column values.

        Args:
            column_values (List[Union[int, float]]): The list of values to analyze.

        Returns:
            Union[int, float]: The median of the values in the list.
        """
        return NativeStatistics.Statistics.calculate_median(column_values)

    @staticmethod
    def calculate_variance(column_values: List[Union[int, float]]) -> float:
        """
        Calculate the variance of a list of column values.

        Args:
            column_values (List[Union[int, float]]): The list of values to analyze.

        Returns:
            float: The variance of the values in the list.
        """
        return NativeStatistics.Statistics.calculate_variance(column_values)

    @staticmethod
    def calculate_sd(column_values: List[Union[int, float]]) -> float:
        """
        Calculate the standard deviation of a list of column values.

        Args:
            column_values (List[Union[int, float]]): The list of values to analyze.

        Returns:
            float: The standard deviation of the values in the list.
        """
        return NativeStatistics.Statistics.calculate_sd(column_values)

    @staticmethod
    def frequency_count(column_values: List[Union[int, float]]) -> dict:
        """
        Count the frequency of each value in a list of column values.

        Args:
            column_values (List[Union[int, float]]): The list of values to analyze.

        Returns:
            dict: A dictionary where the keys are values from the list,
                and the values are their corresponding frequencies.
        """
        return NativeStatistics.Statistics.frequency_count(column_values)

    @staticmethod
    def calculate_correlation(column_values1: List[Union[int, float]],
                              column_values2: List[Union[int, float]]) -> float:
        """
        Calculate the correlation coefficient between two lists of column values.

        Args:
            column_values1 (List[Union[int, float]]): The first list of values to analyze.
            column_values2 (List[Union[int, float]]): The second list of values to analyze.

        Returns:
            float: The correlation coefficient between the two lists of values.
        """
        return NativeStatistics.Statistics.calculate_correlation(column_values1, column_values2)

    @staticmethod
    def draw_histogram(column_values: List[Union[int, float]]) -> str:
        """
        Generate a textual histogram for a given list of column values.

        Args:
            column_values (List[Union[int, float]]): The list of values to generate a histogram for.

        Returns:
            str: A textual representation of the histogram.
        """
        return NativeStatistics.Statistics.draw_histogram(column_values)

    @staticmethod
    def calculate_skewness(column_values: List[Union[int, float]]) -> float:
        """
        Calculate the skewness of a list of column values.

        Args:
            column_values (List[Union[int, float]]): The list of values to analyze.

        Returns:
            float: The skewness of the values in the list.
        """
        mean = NativeStatistics.Statistics.calculate_mean(column_values)
        sd = NativeStatistics.Statistics.calculate_sd(column_values)
        n = len(column_values)
        return sum(((x - mean) / sd) ** 3 for x in column_values) * (n / ((n - 1) * (n - 2))) if n > 2 else 0

    @staticmethod
    def calculate_kurtosis(column_values: List[Union[int, float]]) -> float:
        """
        Calculate the kurtosis of a list of column values.

        Args:
            column_values (List[Union[int, float]]): The list of values to analyze.

        Returns:
            float: The kurtosis of the values in the list.
        """
        mean = NativeStatistics.Statistics.calculate_mean(column_values)
        sd = NativeStatistics.Statistics.calculate_sd(column_values)
        n = len(column_values)
        return sum(((x - mean) / sd) ** 4 for x in column_values) * (n * (n + 1)) / ((n - 1) * (n - 2) * (n - 3)) - (3 * ((n - 1) ** 2) / ((n - 2) * (n - 3))) if n > 3 else 0

    @staticmethod
    def calculate_iqr(column_values: List[Union[int, float]]) -> float:
        """
        Calculate the Interquartile Range (IQR) of a list of column values.

        Args:
            column_values (List[Union[int, float]]): The list of values to analyze.

        Returns:
            float: The interquartile range (IQR) of the values in the list.
        """
        sorted_values = sorted(column_values)
        n = len(sorted_values)
        q1 = sorted_values[n // 4]
        q3 = sorted_values[3 * n // 4]
        return q3 - q1

    @staticmethod
    def calculate_covariance(column_values1: List[Union[int, float]],
                              column_values2: List[Union[int, float]]) -> float:
        """
        Calculate the covariance between two lists of column values.

        Args:
            column_values1 (List[Union[int, float]]): The first list of values to analyze.
            column_values2 (List[Union[int, float]]): The second list of values to analyze.

        Returns:
            float: The covariance between the two lists of values.
        """
        mean1 = NativeStatistics.Statistics.calculate_mean(column_values1)
        mean2 = NativeStatistics.Statistics.calculate_mean(column_values2)
        return sum((x - mean1) * (y - mean2) for x, y in zip(column_values1, column_values2)) / len(column_values1)

    def __repr__(self) -> str:
        """
        Return a string representation of the Statistics object.

        Returns:
            str: A string representation of the Statistics instance.
        """
        headers = self.get_headers()
        return f"<Statistics(headers={headers})>"

    def __getitem__(self, key: str) -> List[Any]:
        """
        Access a column by name using indexing syntax.

        Args:
            key (str): The name of the column to retrieve.

        Returns:
            List[Any]: A list of values from the specified column.
        """
        return self.get_column(key)
