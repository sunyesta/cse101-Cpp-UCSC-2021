# HW3: Range searching with AVL trees

Fills an AVL tree with given inputs and counts the number of strings (currently stored) that are lexicographically between 2 given strings. 

## Usage

### Input Format
Each line of the input file will be of the following two forms:
`i <STRING>`
or
`r <STRING1> <STRING2>`

The first line above means insert the string into the tree.

The second line above means: count the number of strings (currently stored)
that are lexicographically between STRING1 and STRING2. 

in other words we want to find all the strings such that `STRING1 ≤ STR ≤ STRING2`

##### Running

    $ wordrange <input file> <output file>

### Output Format
each line of the output will store the solution to a `r <STRING1> <STRING2>` input

## Build
    $ make
    or
    $ make all




## Cleaning
    $ make clean

