# Scientific Toolbox in C++ for Statistics and Integration v2

![Scientific Toolbox Presentation Image](./assets/Scientific_toolbox_image.jpg)

This project contains the material for the third homework assignment of the *Advanced Programming course* for the academic year 2024-25. This course is offered jointly by SISSA (International School for Advanced Studies) and UniTS (Università degli Studi di Trieste), Trieste, Italy.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Structure](#structure)
- [Usage](#usage)
- [Student Notebook](#student-notebook)
- [Integration Notebook](#integration-notebook)
- [Implementation Choices](#implementation-choices)
- [Tested On](#tested-on-)
- [Contributions](#contributions)
- [References](#references)

## Introduction

This project presents an advanced Scientific Toolbox for Statistical Analysis and Integration, meticulously designed to streamline complex tasks and deliver powerful, user-friendly solutions. By combining cutting-edge statistical methods with an intuitive CLI, this toolbox empowers researchers, analysts, and professionals to extract meaningful insights with ease and efficiency. Whether tackling intricate datasets or integrating diverse analytical processes, this tool redefines simplicity and precision in statistical analysis. This version of the toolbox, presents a new cutting-edge integration between C++ and Python, enhancing performance and simplicity.

## Features 

- **Statistical Module**: Allow the user to run analysis on a dataset in .csv format. In this module, they are also implemented several tests and an application developed with this Toolbox refered to a student's Dataset.

- **Integration Module**: A very intuitive and user-friendly module to approximate definite integrals using custom functions with various methods and personalized parameters. A new notebook using this module has been implemented. 

## Prerequisites

- C++ compiler (e.g., g++).
- cmake (3.15 MINIMUM REQUIRED)
- Python3. (built with python 3.10.16)
- Pybind11 (pybind11-dev 2.9.1-2)

## Structure

- `src/`: Contains source files
    - `statistics/`: Statistics module  
    - `integration/`: Integration module  
    - `bindings/`: Binds for c++ and python
- `assets`: Directory for Images 
- `build/`: Directory for binary files and library built with CMakeLists.txt
- `extern/`: Contains auxiliary libraries
    - `pybind11/`: Library that allows to work with c++ and python
- `datasets/`: Contains the datasets in csv format
- `tests/`: Contains several tests scripts for the used modules
    - `cpp/`: Tests for the source code
    - `python/`: Tests for python binding code
- `notebooks/`: Contains the notebooks producted using this framework
- `modules/`: Contains OOP classes in Python to implement and extend c++ modules
    `scientific_module/`: Extended module in python for bindings
- `output/`: Directory for the output
    - `integration/`
    - `statistics/`
- `build_library.sh`: Script for building the project

## Usage

*Installation*

1. **Clone or Download the Repository**  

   Once the repository is uploaded to GitHub, clone or download it to your local machine.

   ```bash
   git clone https://github.com/tavaa/ADVANCED_PROGRAMMING_24_25.git
   cd ADVANCED_PROGRAMMING_24_25/Homework03/
   ```

3. **Build the Project**  

   In order to build the scientific_toolbox, run the bash script that works with CMakeLists.txt

   ```bash
   chmod +x build_library.sh
   ./build_library.sh
   ```
   Once the script has been executed, you will find something like "scientific_toolbox.cpython-310-x86_64-linux-gnu.so" on the `build/src/` directory.

4. **Create a Virtual Environment for your project**

   ```python
    python3.10 -m venv venv
   ```

   Load the virtual environment:

   - On windows PowerShell: `.\venv\Scripts\activate.ps1`
   - On Linux and Git Bash / macOs: `source venv/bin/activate`

   Deactivate once termined:

   ```python
    deactivate
   ```
   
5. **Install Python Dependencies**

    ```bash
    pip install -r requirements.txt
    ```

*Usage*

Once the prerequisites has been satisfied, you can choose what to explore inside the toolbox:

**Notebooks**

Navigate into `notebooks/` folder and run cells inside the two files:

- `A01_notebook_integration.ipynb`: Run cells and read markdown. 
- `A02_notebook_statistics.ipynb`: Run cells and read markdown. 

**Tests**

Navigate into `tests/` folder and choose what to test:

- `cpp/`: tests for source code:
  
    ```bash
    chmod +x run_test_cpp.sh
    ./run_test_cpp.sh
    ```

- `python/`: tests for bindings code:

    ```bash
    chmod +x run_test_py.sh
    ./run_test_py.sh
    ```

## Student Notebook

Navigate into `notebooks/` folder to see an example of python notebook of the framework. This example has been elaborated in order to explain the performed analysis and the evaluation of the results. In particular, we have presented:

* Summary Statistics
* Performance by Gender
* Impact of Parental Education
* Impact of Test Preparation
* Score Distribution by Race

## Integration Notebook

Navigate into `notebooks/` folder to see an example of python notebook of the framework. This example has been elaborated in order to demostrate the use of the toolbox with the scientific module to solve and approximate definite integrals applyed on real-life scenario:

* Exercise 1 shows a calculation of the volume of a rotational solid.
* Exercise 2 shows a Calculation of the distance covered by a moving object. 

## Implementation Choices

- The data acquisition from the CSV file was managed using `std::optional<std::variant<int, double, std::string>>` to efficiently capture the contents of individual cells, while accounting for potential missing or invalid values. This approach ensures flexibility and robustness when handling incomplete datasets. Once the data was extracted, it was processed using custom-built statistical modules designed for tasks such as data summarization, variance analysis, and correlation computation.

- Additionally, a dedicated module was developed to approximate definite integrals.

- We have implemented an instance of CSVParser within the Statistics module to enhance the module's independent usability.

- We utilize bindings between C++ and Python through the pybind11 module. All source code has been bound using a main_binding script that organizes and modularizes the specific bindings    implemented for each module (Statistics, CSVParser, Integration).

- A scientific module has been developed using Pythonic code and classes. We have prioritized the inclusion of docstrings, magic methods, static and class methods, list comprehensions, and  decorators. The objective of this module is to establish Python bindings and extend them with new Pythonic functions.

- The entire project has been built using CMakeLists.txt, a widely-used approach for building large and cross-platform projects.

- In conclusion, we have chosen to implement and apply our module in several notebooks.

## Tested On

* Ubuntu 22.04.3
* Ubuntu (WSL)
* Debian 12.8
* Kali Linux 2024.03

## Contribution

**Authors**

* Tiozzo Netti Eleonora <eleonora.tiozzo@studenti.units.it>
* Tavano Matteo <matteo.tavano@studenti.units.it>

**List of contributions**

Tiozzo Netti Eleonora:
- Conceived the statistics module.
- wrote the CMakeLists.txt.
- Drafted the computations to perform.
- Wrote the list with input from the authors.
- Wrote the student analysis notebook.

Tavano Matteo:
- Designed the tests module and correlated analyses.
- Developed the modularization of the project.
- Worked out some implementation details. 
- Planned and carried out the functionality of the apps module.
- Wrote the Integration notebook.

Both authors discussed the results and contributed equally to shape the project.

## References

1. Advanced Programming course: https://github.com/pcafrica/advanced_programming_2024-2025
2. Pybind11: https://github.com/pybind/pybind11
3. Pybind11 example usage: https://github.com/tdegeus/pybind11_examples
4. Kaggle datasets: https://www.kaggle.com/datasets/
5. Numerical integration: https://math.umd.edu/~petersd/460/numint460.pdf
6. std::variant: https://en.cppreference.com/w/cpp/utility/variant
7. Mastering Datasets operations in C++: https://cppscripts.com/cpp-dataset
8. Awesome Scientific Computing: https://github.com/nschloe/awesome-scientific-computing


