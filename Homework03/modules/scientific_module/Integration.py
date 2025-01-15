import os
import sys
import math

# Add the build directory to the system path to import the C++ bindings
build_dir = os.path.abspath("../build/src/")
sys.path.append(build_dir)

from scientific_toolbox import integration as cpp_integration

class Integration:
    """
    Python wrapper for the C++ Integration module, providing a high-level interface
    for numerical integration with additional functionality.
    """
    def __init__(self):
        """
        Initialize the Python Integration wrapper.
        """
        self._cpp_integration = cpp_integration.Integration()
        self.method = None
        self.a = None
        self.b = None
        self.N = None
        self.result = None

    @staticmethod
    def function_evaluator(expression):
        """
        Create a Python function from a string expression for integration.

        Args:
            expression (str): A string representing a mathematical expression (e.g., "math.sin(x)").

        Returns:
            function: A Python function that evaluates the expression for a given x.
        """
        def evaluator(x):
            return eval(expression, {"x": x, "math": math})

        return evaluator

    def integrate(self, method, f, a, b, N):
        """
        Compute the integral of a function using a specified numerical method.

        Args:
            method (str): The integration method to use ("midpoint", "trapezoidal", "simpson").
            f (function): The function to integrate.
            a (float): The start of the integration interval.
            b (float): The end of the integration interval.
            N (int): The number of subintervals.

        Returns:
            float: The computed integral value.

        Raises:
            ValueError: If the specified method is invalid.
        """
        self.method = method
        self.a = a
        self.b = b
        self.N = N

        if method == "midpoint":
            self.result = self._cpp_integration.midpoint_rule(f, a, b, N)
        elif method == "trapezoidal":
            self.result = self._cpp_integration.trapezoidal_rule(f, a, b, N)
        elif method == "simpson":
            self.result = self._cpp_integration.simpsons_rule(f, a, b, N)
        else:
            raise ValueError("Invalid integration method. Supported methods: 'midpoint', 'trapezoidal', 'simpson'.")

        return self.result

    @staticmethod
    def calculate_step_size(a, b, n):
        """
        Calculate the step size for integration.

        Args:
            a (float): The start of the interval.
            b (float): The end of the interval.
            n (int): The number of subintervals.

        Returns:
            float: The step size.
        """
        return cpp_integration.Integration.step_size(a, b, n)

    @classmethod
    def from_expression(cls, expression, method, a, b, N):
        """
        Create an instance of Integration and compute an integral directly from a mathematical expression.

        Args:
            expression (str): A string representing the mathematical function to integrate.
            method (str): The integration method to use ("midpoint", "trapezoidal", "simpson").
            a (float): The start of the integration interval.
            b (float): The end of the integration interval.
            N (int): The number of subintervals.

        Returns:
            float: The computed integral value.
        """
        instance = cls()
        f = cls.function_evaluator(expression)
        instance.integrate(method, f, a, b, N)
        return instance

    def __repr__(self):
        """
        Return a string representation of the Integration class.

        Returns:
            str: The string representation.
        """
        if self.result is not None:
            return (f"<Integration(method={self.method}, interval=[{self.a}, {self.b}], "
                    f"subintervals={self.N}, result={self.result:.5f})>")
        else:
            return "<Integration(not computed)>"