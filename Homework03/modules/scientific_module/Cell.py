from typing import List, Union, Optional, Any

class Cell:
    """
    Represents a single cell in the dataset, capable of holding strings, numbers, or null values.

    Attributes:
        value (Optional[Union[str, int, float]]): The value stored in the cell.
    """

    def __init__(self, value: Optional[Union[str, int, float]]):
        """
        Initializes the Cell instance with the given value.

        Args:
            value (Optional[Union[str, int, float]]): The value to store in the cell.
        """
        self.value = value

    def __repr__(self):
        """
        Returns a string representation of the cell's value.

        Returns:
            str: The string representation of the cell's value.
        """
        return str(self.value)

    def __eq__(self, other):
        """
        Compares this cell with another cell or value for equality.

        Args:
            other (Any): The object to compare against.

        Returns:
            bool: True if the values are equal, otherwise False.
        """
        if isinstance(other, Cell):
            return self.value == other.value
        return False
