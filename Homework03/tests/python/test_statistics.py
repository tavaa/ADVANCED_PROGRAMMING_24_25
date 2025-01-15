import sys
import os
import unittest

build_dir = os.path.abspath("../../build/src/")  
sys.path.append(build_dir)

from scientific_toolbox import statistics

class TestStatistics(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.dataset_path = "../../datasets/gym_members_exercise_tracking.csv"
        cls.statistics = statistics.Statistics(cls.dataset_path, delimiter=",", has_headers=True)

    def test_get_headers(self):
        headers = self.statistics.get_headers()
        self.assertIsInstance(headers, list)
        self.assertGreater(len(headers), 0, "Headers should not be empty")

    def test_get_column(self):
        column = self.statistics.get_column("Age")
        self.assertIsInstance(column, list)
        self.assertGreater(len(column), 0, "Column should not be empty")

    def test_calculate_mean(self):
        column = self.statistics.get_column("Age")
        mean = statistics.Statistics.calculate_mean(column)
        self.assertIsInstance(mean, (int, float), "Mean should be numeric")

    def test_calculate_median(self):
        column = self.statistics.get_column("Age")
        median = statistics.Statistics.calculate_median(column)
        self.assertIsInstance(median, (int, float), "Median should be numeric")

    def test_calculate_variance(self):
        column = self.statistics.get_column("Age")
        variance = statistics.Statistics.calculate_variance(column)
        self.assertIsInstance(variance, (int, float), "Variance should be numeric")

    def test_calculate_sd(self):
        column = self.statistics.get_column("Age")
        sd = statistics.Statistics.calculate_sd(column)
        self.assertIsInstance(sd, (int, float), "Standard deviation should be numeric")

    def test_frequency_count(self):
        column = self.statistics.get_column("Gender")
        freq_count = statistics.Statistics.frequency_count(column)
        self.assertIsInstance(freq_count, dict, "Frequency count should be a dictionary")
        self.assertGreater(len(freq_count), 0, "Frequency count should not be empty")

    def test_calculate_correlation(self):
        column1 = self.statistics.get_column("Age")
        column2 = self.statistics.get_column("Session_Duration_(hours)")
        correlation = statistics.Statistics.calculate_correlation(column1, column2)
        self.assertIsInstance(correlation, float, "Correlation should be a float")

    def test_draw_histogram(self):
        column = self.statistics.get_column("Age")
        histogram = statistics.Statistics.draw_histogram(column)
        self.assertIsInstance(histogram, str, "Histogram should be a string")
        self.assertGreater(len(histogram), 0, "Histogram output should not be empty")

    def test_min_value(self):
        column = self.statistics.get_column("Age")
        min_val = statistics.Statistics.min_value(column)
        self.assertIsInstance(min_val, (int, float), "Minimum value should be numeric")

    def test_max_value(self):
        column = self.statistics.get_column("Age")
        max_val = statistics.Statistics.max_value(column)
        self.assertIsInstance(max_val, (int, float), "Maximum value should be numeric")

    def test_exceptions_invalid_column(self):
        with self.assertRaises(statistics.RuntimeError):
            self.statistics.get_column("NonExistentColumn")

    def test_exceptions_invalid_file_path(self):
        with self.assertRaises(statistics.RuntimeError):
            statistics.Statistics("invalid_path.csv", delimiter=",", has_headers=True)

if __name__ == "__main__":
    unittest.main()




