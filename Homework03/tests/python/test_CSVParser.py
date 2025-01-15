import unittest
import os
import sys

# Aggiorna il percorso per includere il binding compilato
build_dir = os.path.abspath("../../build/src/")
sys.path.append(build_dir)

from scientific_toolbox import CSVParser, statistics

class TestCSVParser(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.dataset_path = "../../datasets/gym_members_exercise_tracking.csv"  # Modifica con il percorso reale
        cls.parser = CSVParser.CSVParser(cls.dataset_path, delimiter=",", has_headers=True)
        cls.parser.parse()

    def test_get_headers(self):
        headers = self.parser.getHeaders()
        self.assertIsNotNone(headers, "I titoli non devono essere None.")
        self.assertIsInstance(headers, list, "I titoli devono essere una lista.")
        self.assertGreater(len(headers), 0, "I titoli non devono essere vuoti.")

    def test_get_header_index(self):
        headers = self.parser.getHeaders()
        if headers:
            header = headers[0]
            index = self.parser.getHeaderIndex(header)
            self.assertGreaterEqual(index, 0, "L'indice del titolo deve essere valido.")
        else:
            self.skipTest("Il dataset non contiene titoli.")

    def test_get_num_rows(self):
        num_rows = self.parser.getNumRows()
        self.assertGreaterEqual(num_rows, 0, "Il numero di righe deve essere non negativo.")

    def test_get_head(self):
        head = self.parser.getHead(5)
        self.assertLessEqual(len(head), 5, "Il metodo getHead dovrebbe restituire al massimo 5 righe.")
        self.assertIsInstance(head, list, "Il metodo getHead dovrebbe restituire una lista.")
    
    def test_get_tail(self):
        tail = self.parser.getTail(5)
        self.assertLessEqual(len(tail), 5, "Il metodo getTail dovrebbe restituire al massimo 5 righe.")
        self.assertIsInstance(tail, list, "Il metodo getTail dovrebbe restituire una lista.")

    def test_get_row(self):
        if self.parser.getNumRows() > 0:
            row = self.parser.getRow(0)
            self.assertIsInstance(row, list, "La riga dovrebbe essere una lista.")
        else:
            self.skipTest("Il dataset non contiene righe.")

    def test_get_column(self):
        headers = self.parser.getHeaders()
        if headers:
            column_name = headers[4]
            column = self.parser[column_name]
            self.assertIsInstance(column, list, "La colonna dovrebbe essere una lista.")
        else:
            self.skipTest("Il dataset non contiene titoli.")
    
    def test_exceptions_invalid_column(self):
        with self.assertRaises(statistics.RuntimeError):
            self.parser["NonExistentColumn"]

if __name__ == "__main__":
    unittest.main()
