# Scientific Toolbox in C++ for Statistics and Integration

![Scientific Toolbox Presentation Image](./assets/Scientific_toolbox_image.jpg)

This project contains the material for the second homework assignment of the *Advanced Programming course* for the academic year 2024-25. This course is offered jointly by SISSA (International School for Advanced Studies) and UniTS (Università degli Studi di Trieste), Trieste, Italy.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Structure](#structure)
- [Usage](#usage)
- [Student Analysis](#student-analysis)
- [Implementation Choices](#implementation-choices)
- [Tested On](#tested-on-)
- [Contributions](#contributions)
- [References](#references)

## Introduction

This project presents an advanced Scientific Toolbox for Statistical Analysis and Integration, meticulously designed to streamline complex tasks and deliver powerful, user-friendly solutions. By combining cutting-edge statistical methods with an intuitive CLI, this toolbox empowers researchers, analysts, and professionals to extract meaningful insights with ease and efficiency. Whether tackling intricate datasets or integrating diverse analytical processes, this tool redefines simplicity and precision in statistical analysis.

## Features 

- **Statistical Module**: Allow the user to run analysis on a custom dataset in .csv format. In this module, they are also implemented several tests and an application developed with this Toolbox refered to a student's Dataset.

- **Integration Module**: A very intuitive and user-friendly module to approximate definite integrals using custom functions, parsed on CLI, with varyous methods and personalized parameters.

## Prerequisites

- C++ compiler (e.g., g++, clang++).
- Make (optional, if you are using Makefile).
- Python3.

## Structure

- `src/`: Contains source files
    - `statistics/`: Statistics module  
    - `integration/`: Integration module  
- `assets`: Directory for Images/example analysis in pdf format
- `build/`: Directory for binary files
- `include/`: Contains auxiliary libraries
    - `boost_1_86_0/`: Library containing Tokenizer and Histogram modules
    - `muparserx-4.0.12/`: Library containing function parsing module
- `datasets/`: Contains the datasets in csv format
- `lib/`: Contains libraries built with source code for independent usage
- `tests/`: Contains several tests scripts for the used modules
    - `CSVParser/`
    - `Statistics/`
    - `Integration/`
- `apps/`: Contains the application producted using this framework
    - `custom/`: for custom statistics analysis
    - `integration/`: for custom integration
    - `student_analysis/`: an example statistical analysis on a student dataset
- `output/`: Directory for the output
    - `integration/`
    - `statistics/`
- `ScientificToolbox.py`: Script for building the project

## Usage

*Installation*

1. **Clone or Download the Repository**
   ```bash
   git clone https://github.com/tavaa/ADVANCED_PROGRAMMING_24_25.git
   cd Homework02 
   ```

3. **Prepare Dependencies**  
   Navigate to the `/include` directory:  
   ```bash
   cd include
   ```

Download Boost 1.86.0 from boost.org and extract its content into this folder.
https://www.boost.org/

Download libmuparserx 4.0.12 from muparserx and extract its content into this folder.
https://beltoforion.de/en/muparserx/

3. **Return to the Main Directory**
    ```bash
    cd ..
    ```

4. **Install Python Dependencies**
    ```bash
    pip install -r requirements.txt
    ```

5. **Launch Main Script**
    ```bash
    python ScientificToolbox.py
    ```

*Usage*

Choose the module to use, through the CLI. It will be easy and intuitive to understand how to use.

**Custom Statistics Analysis**

1. Insert a dataframe in .csv folder into `/dataset` directory.
2. Modify the `Custom_analysis.cpp` script in order to perform your own Analysis.
3. Once you have complete, save the script and run again the python script.
4. The output of your analysis must be specified in your script (default in `/output/statistics/`).
5. You can use `/apps/Custom_analysis.cpp` as the template of your implementation.

**Custom Integration**

1. Run the main python script, then choose 2, then 1.
2. Parse your expression (no spaces).
3. Select other parameters (lower bound, upper bound, N, method).
4. The output will be saved into `/output/integration/`

*Debug*

Sometimes, Statistics module get bugged. No worry, just re-run the script, or navigate into the folders and run bash scripts.

You can use built-in tests to ensure the functionality of the framework.

## Student Analysis

Navigate into `assets/` folder to see an example of output of the framework. This example has been elaborated in order to explain the performed analysis and the evaluation of the results. In particular, we have presented:

* Summary Statistics
* Performance by Gender
* Impact of Parental Education
* Impact of Test Preparation
* Score Distribution by Race

## Implementation Choices

The data acquisition from the CSV file was handled using `std::optional<std::variant<int, double, std::string>>` to efficiently capture the contents of individual cells, accounting for potential missing or invalid values. This approach ensures flexibility and robustness when dealing with incomplete datasets. Once the data was extracted, it was processed using custom-built statistical modules designed for tasks such as data summarization, variance analysis, and correlation computation. Additionally, a dedicated module was implemented to approximate definite integrals. This module leverages numerical integration techniques and exposes its functionality through a **Command-Line Interface (CLI)**, enabling users to compute integrals of specified functions directly from the terminal. The integration module includes tailored functions for common scenarios, ensuring precision and usability in a wide range of applications.

## Tested On

* Ubuntu 22.04.3
* Ubuntu (WSL)
* Debian 12.8
* Kali Linux 2024.03
* Termux

## Contribution

**Authors**

Tiozzo Netti Eleonora <eleonora.tiozzo@studenti.units.it>
Tavano Matteo <matteo.tavano@studenti.units.it>

**List of contributions**

Tiozzo Netti Eleonora:
- Conceived the statistics module
- wrote the Makefiles
- Drafted the computations to perform
- Wrote the list with input from the authors

Tavano Matteo:
- Designed the tests module and correlated analyses
- Developed the modularization of the project
- Worked out some implementation details 
- Planned and carried out the functionality of the apps module.

Both authors discussed the results and contributed equally to shape the project.

## References

1. Advanced Programming course: https://github.com/pcafrica/advanced_programming_2024-2025
2. muparserx repository: https://github.com/beltoforion/muparserx
3. boostorg/histogram repository: https://github.com/boostorg/histogram
4. boostorg/tokenizer respository: https://github.com/boostorg/tokenizer
5. boostorg/boost respository: https://github.com/boostorg/boost
6. Kaggle datasets: https://www.kaggle.com/datasets/
7. Numerical integration: https://math.umd.edu/~petersd/460/numint460.pdf
8. std::variant: https://en.cppreference.com/w/cpp/utility/variant
9. Mastering Datasets operations in C++: https://cppscripts.com/cpp-dataset


