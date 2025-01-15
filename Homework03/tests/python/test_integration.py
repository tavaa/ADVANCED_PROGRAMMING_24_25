import sys
import os
import unittest

build_dir = os.path.abspath("../../build/src/")  
sys.path.append(build_dir)

from scientific_toolbox import integration

class TestIntegration(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.integrator = integration.Integration()

    def test_midpoint_rule(self):

        def func(x):
            return x ** 2

        result = self.integrator.midpoint_rule(func, 0, 1, 1000)
        self.assertIsInstance(result, (int, float), "Midpoint rule result should be numeric")
        self.assertGreater(result, 0, "Midpoint rule result should be positive")

    def test_trapezoidal_rule(self):

        def func(x):
            return x ** 2

        result = self.integrator.trapezoidal_rule(func, 0, 1, 1000)
        self.assertIsInstance(result, (int, float), "Trapezoidal rule result should be numeric")
        self.assertGreater(result, 0, "Trapezoidal rule result should be positive")

    def test_simpsons_rule(self):

        def func(x):
            return x ** 2

        result = self.integrator.simpsons_rule(func, 0, 1, 1000)
        self.assertIsInstance(result, (int, float), "Simpson's rule result should be numeric")
        self.assertGreater(result, 0, "Simpson's rule result should be positive")

    def test_exceptions_invalid_function(self):

        with self.assertRaises(integration.InvalidArgumentError):
            self.integrator.midpoint_rule(None, 0, 1, 1000)
        
    def test_exceptions_invalid_limits(self):

        def func(x):
            return x ** 2
        with self.assertRaises(integration.InvalidArgumentError):
            self.integrator.midpoint_rule(func, 1, 0, 1000)
            
    def test_exceptions_invalid_intervals(self):
 
        def func(x):
            return x ** 2
        with self.assertRaises(integration.InvalidArgumentError):
            self.integrator.midpoint_rule(func, 0, 1, 0)

if __name__ == "__main__":
    unittest.main()
