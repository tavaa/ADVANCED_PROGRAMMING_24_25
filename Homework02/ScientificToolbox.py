import os
import subprocess
import pyfiglet
from termcolor import colored

def print_ascii_art():
    ascii_art = pyfiglet.figlet_format("SCIENTIFIC TOOLBOX", font = "slant")
    colored_ascii = colored(ascii_art, "red")
    print(colored_ascii)

def display_module_1_options():
    print("\nSelect an option for Module 1:")
    print("[1] Run Example Application")
    print("[2] Run Custom Application")
    print("[3] Run CSVParser Tests")
    print("[4] Run Statistics Tests")
    choice = input("Enter your choice: ")

    if choice == '1':
        run_example_application()
    elif choice == '2':
        run_custom_application()
    elif choice == '3':
        run_csvparser_tests()
    elif choice == '4':
        run_statistics_tests()
    else:
        print("Invalid choice, please select again.")
        display_module_1_options()

def run_example_application():
    print("Running Example Application...")

    test_dir = "/apps/student_analysis/"
    bash_file = "run_analysis.sh"

    try:

        os.chdir(os.getcwd() + test_dir)

        if not os.path.isfile(bash_file):
            raise FileNotFoundError(f"File '{bash_file}' not found in directory '{test_dir}'.")

        os.chmod(bash_file, 0o755)

        result = subprocess.run(["./" + bash_file], check=True, text=True, capture_output=True)

        os.chdir("../../output/statistics/")  

        file_name = "Cleaned_Students_Performance_results.txt"

        try:
   
            with open(file_name, "r") as file:
                content = file.read()
                print(content)

        except FileNotFoundError:
            print(f"File {file_name} not found .")
        except Exception as e:
            print(f"Error: {e}")

    except subprocess.CalledProcessError as e:
        print(f"Error while executing bash file:\n{e.stderr}")
    except Exception as e:
        print(f"Error: {e}")
        os.chdir("../../")  


def run_custom_application():
    print("Running Custom Application...")

    test_dir = "/apps/custom/"
    bash_file = "run_custom_analysis.sh"

    try:

        os.chdir(os.getcwd() + test_dir)

        if not os.path.isfile(bash_file):
            raise FileNotFoundError(f"File '{bash_file}' not found in directory '{test_dir}'.")

        os.chmod(bash_file, 0o755)

        result = subprocess.run(["./" + bash_file], check=True, text=True, capture_output=True)
        
        print("This is a custom analysis module. Insert your csv into /dataset/ folder.")
        print("Follow the example of the student analysis to perform your statistical analysis.")

        os.chdir("../../")  

    except subprocess.CalledProcessError as e:
        print(f"Error while executing bash file:\n{e.stderr}")
    except Exception as e:
        print(f"Error: {e}")
        os.chdir("../../")  


def run_csvparser_tests():

    print("Running CSVParser Tests...")

    test_dir = "/tests/CSVParser/"
    bash_file = "run_test.sh"

    try:

        os.chdir(os.getcwd() + test_dir)

        if not os.path.isfile(bash_file):
            raise FileNotFoundError(f"File '{bash_file}' not found in directory '{test_dir}'.")

        os.chmod(bash_file, 0o755)

        print("Please enter the CSV name: ")
        result = subprocess.run(["./" + bash_file], check=True, text=True, capture_output=True)

        print("------------------------------------------")
        print(f"Output from run_test.sh:\n{result.stdout}")
        print("This is a test of the CSVParser module.")
        print("The aim is to test the parsing process of the module.")
        
        os.chdir("../../")  

    except subprocess.CalledProcessError as e:
        print(f"Error while executing bash file:\n{e.stderr}")
    except Exception as e:
        print(f"Error: {e}")
        os.chdir("../../")  

def run_statistics_tests():
    print("Running Statistics Tests...")

    test_dir = "/tests/Statistics/"
    bash_file = "run_test.sh"

    try:

        os.chdir(os.getcwd() + test_dir)

        if not os.path.isfile(bash_file):
            raise FileNotFoundError(f"File '{bash_file}' not found in directory '{test_dir}'.")

        os.chmod(bash_file, 0o755)

        result = subprocess.run(["./" + bash_file], check=True, text=True, capture_output=True)

        print("------------------------------------------")
        print(f"Output from run_test.sh:\n{result.stdout}")
        print("This is a test of the Statistics module, performed on the default CSV, gym_members_exercise_tracking.csv")
        print("Some statistics of interest, such as mean, median, variance, sd, correlation are tested on this dataset.")
        print("The aim of this module is to evaluate the single components.")

        os.chdir("../../")  

    except subprocess.CalledProcessError as e:
        print(f"Error while executing bash file:\n{e.stderr}")
    except Exception as e:
        print(f"Error: {e}")
        os.chdir("../../") 

def display_module_2_options():
    print("\nSelect an option for Module 2:")
    print("[1] Run Custom Integration")
    print("[2] Run Integration test")
    choice = input("Enter your choice: ")

    if choice == '1':
        run_custom_integration()
    elif choice == '2':
        run_integration_test()
    else:
        print("Invalid choice, please select again.")
        display_module_2_options()

def run_custom_integration():
    print("Running Custom Integration ...")

    test_dir = "/apps/Integration/"
    bash_file = "run_integration.sh"

    try:

        os.chdir(os.getcwd() + test_dir)

        if not os.path.isfile(bash_file):
            raise FileNotFoundError(f"File '{bash_file}' not found in directory '{test_dir}'.")

        os.chmod(bash_file, 0o755)

        function = input("Insert a function to approximate (es. 'sin(x)', 'x^2 + 3*x'): ")
        lower_bound = input("Insert the lower bound of the integral (a): ")
        upper_bound = input ("Insert the upper bound of the integral (b): ")
        N = input("Insert the number of intervals for the approximation (N): ")
        method = input("Choose the Integration method ('midpoint', 'trapezoidal', 'simpson'): ")

        subprocess.run(["./" + bash_file, function, lower_bound, upper_bound, N, method], check=True)
    
    except subprocess.CalledProcessError as e:
        print(f"Error while executing bash script:\n{e.stderr}")
    except Exception as e:
        print(f"Error: {e}")
    finally:
        os.chdir("../..")

def run_integration_test():
    print("Running Integration Test")

    test_dir = "/tests/Integration/"
    bash_file = "run_test.sh"

    try:

        os.chdir(os.getcwd() + test_dir)

        if not os.path.isfile(bash_file):
            raise FileNotFoundError(f"File '{bash_file}' not found in directory '{test_dir}'.")

        os.chmod(bash_file, 0o755)
        print(f"Updated permissions for: {bash_file}")

        result = subprocess.run(["./" + bash_file], check=True, text=True, capture_output=True)

        print("------------------------------------------")
        print(f"Output from run_test.sh:\n{result.stdout}")
        print("This is a test of the single components of the Integration module.")
        print("The default function tested is \"sin(x)\", from 0 to pi, using N = 100 intervals.")
        print("The result of the approximation is described above using several methods.")

        os.chdir("../../")  

    except subprocess.CalledProcessError as e:
        print(f"Error while executing bash file:\n{e.stderr}")
    except Exception as e:
        print(f"Error: {e}")
        os.chdir("../../") 


def main():
    print_ascii_art()  
    
    while True:
        print("\nSelect a module to use:")
        print("[1] Statistics module")
        print("[2] Integration module")
        print("[0] Exit")

        choice = input("Insert module: ")

        if choice == "1":
            display_module_1_options()  
        elif choice == "2":
            display_module_2_options()  
        elif choice == "0":
            print("Bye!")
            break  
        else:
            print("Try again!")

if __name__ == "__main__":
    main()
