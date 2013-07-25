/* Hercules Coding Style Overview
 *
 * This header file is intentionally #ifdef'd out as it contains no code that
 * should ever be compiled for Hercules as well as containing materials that may
 * not compile on some platform and compiler combinations.
 *
 * Settings shown below are for Eclipse; equivalent settings are to be used in
 * other editors. For check lists, N indicates no check while Y indicates a
 * check. All C++ elements shown are for Eclipse style documentation purposes
 * only. The associated Eclipse profile for Hercules is in file
 * hercstyle-eclipse.xml.
 *
 * Hercules uses a modified Allman (BSD) coding style.
 *
 *
 * Style files:
 *
 *   Eclipse:   hercules-style.xml
 *
 *
 * Additional deviations not handled by the Eclipse C/C++ Formatter and
 * not shown in the subsequent Eclipse C/C++ Formatter Profile Settings
 * and Examples:
 *
 * 1.   Insert a blank line between declarative and non-declarative
 *      statements and comments.
 *
 * 2.   Avoid the use of C++ comments (//).
 *
 * 3.   Liberally use comments.
 *
 * Example:
 *
 */
#ifdef 0

/******************************************************************************/
/*                                                                            */
/*  foo - Foundational Obfuscated Oratory                                     */
/*                                                                            */
/*  General purpose routine to obfuscate what may otherwise be a perfectly    */
/*  good integer while illuminating an illustration of the Hercules coding    */
/*  style.                                                                    */
/*                                                                            */
/******************************************************************************/

int foo(int bar)
{
    int     x;
    double  y;

    /* Based on bar, and illustrating some nonsensical comments and
     * statements, generate value x as a function of bar, which may be
     * modified by pi, but not pie.
     */
    switch (bar)
    {
    case 0:
        x = 0;
        break;
    case 2:
        x = bar >> 2;
        break;
    default:
        {
            const double pi = 3.14159265;

            /* Default to algorithm 2*pi*(r squared) */
            y = 2 * pi * (double)(bar * bar);
            x = (int)y;
            break;
        }
    }

    return x;
}


/******************************************************************************/
/******************************************************************************/
/***                                                                        ***/
/***         Eclipse C/C++ Formatter Profile Settings and Examples          ***/
/***                                                                        ***/
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*      Indentation                                                           */
/*                                                                            */
/******************************************************************************/

/* Tab Policy:                                               Spaces only
 * Indentation size:                                                   4
 * Tab size:                                                           4
 *
 * Indent:
 * N 'public', 'protected', 'private'
 * Y Statements within function body
 * Y Statements within blocks
 * N Statements within 'switch' body
 * Y Statements within 'case' body
 * Y 'break' statements
 * N Declarations within 'namespace' definition
 * N Empty lines
 */


/******************************************************************************/
/*                                                                            */
/*      Braces                                                                */
/*                                                                            */
/******************************************************************************/

/* Brace positions
 * Class declaration:                           Next line
 * Namespace declaration:                       Next line
 * Function declaration:                        Next line
 * Blocks:                                      Next line
 * Blocks in case statement:                    Next line indented
 * 'switch' statement:                          Next line
 * Initializer list:                            Next line
 * N Keep empty initializer list on one line
 */


/*
 * Indentation and Braces Preview
 */

#include <math.h>

int digits[] =
{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

class Point
{
public:
    Point(double x, double y) :
            x(x), y(y)
    {
    }
    double distance(const Point& other) const;
    int compareX(const Point& other) const;
    double x;
    double y;
};

double Point::distance(const Point& other) const
{
    double dx = x - other.x;
    double dy = y - other.y;
    return sqrt(dx * dx + dy * dy);
}

int Point::compareX(const Point& other) const
{
    if (x < other.x)
    {
        return -1;
    }
    else if (x > other.x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

namespace FOO
{
int foo(int bar) const
{
    switch (bar)
    {
    case 0:
        ++bar;
        break;
    case 1:
        --bar;
    default:
        {
            bar += bar;
            break;
        }
    }
}
} // end namespace FOO


/******************************************************************************/
/*                                                                            */
/*      White Space                                                           */
/*                                                                            */
/******************************************************************************/

/* Insert space:
 *
 * Declarations:
 *
 *   Types:
 *   Y before opening brace of a class
 *   N before colon of base clause
 *   Y after colon of base clause
 *   N before comma in base clause
 *   Y after comma in base clause
 *
 *   Declarator list:
 *   N before comma in declarator list
 *   Y after comma in declarator list
 *
 *   Functions:
 *   N before opening parenthesis
 *   N after opening parenthesis
 *   N before closing parenthesis
 *   N between empty parenthesis
 *   Y before opening brace
 *   N before comma in parameters
 *   Y after comma in parameters
 *
 *   Exception specifications:
 *   Y before opening parenthesis
 *   N after opening parenthesis
 *   N before closing parenthesis
 *   N between empty parenthesis
 *   N before comma in parameters
 *   Y after comma in parameters
 *
 *   Labels:
 *   N before colon
 *   Y after colon
 *
 * Control Statements:
 * N before semicolon
 *
 *   Blocks:
 *   Y before opening brace
 *   Y after closing brace
 *
 *   'if else':
 *   Y before opening parenthesis
 *   N after opening parenthesis
 *   N before closing parenthesis
 *
 *   'for':
 *   Y before opening parenthesis
 *   N after opening parenthesis
 *   N before closing parenthesis
 *   N before semicolon
 *   Y after semicolon
 *
 *   'switch':
 *   N before colon in case
 *   N before colon in default
 *   Y before opening brace
 *   Y before opening parenthesis
 *   N after opening parenthesis
 *   N before closing parenthesis
 *
 *   'while' & 'do while':
 *   Y before opening parenthesis
 *   N after opening parenthesis
 *   N before closing parenthesis
 *
 *   'catch':
 *   Y before opening parenthesis
 *   N after opening parenthesis
 *   N before closing parenthesis
 *
 * Expressions:
 *
 *   Function invocations:
 *   N before opening parenthesis
 *   N after opening parenthesis
 *   N before closing parenthesis
 *   N between empty parenthesis
 *   N before comma in function arguments
 *   Y after comma in function arguments
 *
 *   Assignments:
 *   Y before assignment operator
 *   Y after assignment operator
 *
 *   Initializer list:
 *   Y before opening brace
 *   Y after opening brace
 *   Y before closing brace
 *   N before comma
 *   Y after comma
 *   N between empty braces
 *
 *   Operators:
 *   Y before binary operators
 *   Y after binary operators
 *   N before unary operators
 *   N after unary operators
 *   N before prefix operators
 *   N after prefix operators
 *   N before postfix operators
 *   N after postfix operators
 *
 *   Parenthesized expressions:
 *   N before opening parenthesis
 *   N after opening parenthesis
 *   N before closing parenthesis
 *
 *   Type casts:
 *   N after opening parenthesis
 *   N before closing parenthesis
 *   Y after closing parenthesis
 *
 *   Conditionals:
 *   Y before question mark
 *   Y after question mark
 *   Y before colon
 *   Y after colon
 *
 *   Expression list:
 *   N before comma in expression list
 *   Y after comma in expression list
 *
 * Arrays:
 * N before opening bracket
 * N after opening bracket
 * N before closing bracket
 * N between empty brackets
 *
 * Templates:
 *
 *   Template arguments:
 *   N before opening angle bracket
 *   N after opening angle bracket
 *   N before comma
 *   Y after comma
 *   N before closing angle bracket
 *   Y after closing angle bracket
 *
 *   Template parameters:
 *   N before opening angle bracket
 *   N after opening angle bracket
 *   N before comma
 *   Y after comma
 *   N before closing angle bracket
 *   Y after closing angle bracket
 */


/*
 * Declarations preview
 */

/* Types */
class MyClass: Base1, Base2
{
};

/* Declarator list */
int a = 0, b = 1, c = 2, d = 3;

/* Functions and exception specifications*/
void foo() throw (E0, E1)
{
}
void bar(int x, int y) throw ()
{
}

/* Labels */
label: for (int i = 0; i < argc; i++)
    goto label;


/*
 * Control statements preview
 */

int a = 4;
foo();
bar(x, y);


/* Blocks */
if (true)
{
    return 1;
}
else
{
    return 2;
}

/* 'if-else' */
if (condition)
{
    return foo;
}
else
{
    return bar;
}

/* 'for' */
for (int i = 0, j = argc; i < argc; i++, j--)
{
}

/* 'switch' */
switch (number)
{
case RED:
    return GREEN;
case GREEN:
    return BLUE;
case BLUE:
    return RED;
default:
    return BLACK;
}

/* 'while' and 'do while' */
while (condition)
{
}

do
{
} while (condition);

/* 'catch' */
try
{
    number = Math::parseInt(value);
}
catch (Math::Exception e)
{
}


/*
 * Expressions preview
 */

/* Function invocations */
foo();
bar(x, y);


/* Assignments and Operators */
int a = -4 + -9;
b = a++ / --number;
c += 4;
bool value = true && false;

/* Initializer List */
int array[] =
{ 1, 2, 3 };

/* Parenthesized expressions */
result = (a * (b + c + d) * (e + f));

/* Type casts */
char * s = ((char *) object);

/* Conditionals */
bool value = condition ? true : false;

/* Expression list */
a = 0, b = 1, c = 2, d = 3;


/*
 * Arrays preview
 */

int array[] =
{ 1, 2, 3 };
array[2] = 0;
int * parray = new int[3];
delete[] parray;


/*
 * Template preview
 */

template<typename T1, typename T2> class map
{
};
map<int, int> m;


/******************************************************************************/
/*                                                                            */
/*      New Lines                                                             */
/*                                                                            */
/******************************************************************************/

/* Insert new line
 * N before colon in constructor initializer list
 */


/*
 * New lines preview
 */

class Point
{
public:
    Point(double x, double y) :
            x(x), y(y)
    {
    }

private:
    double x;
    double y;
};


/******************************************************************************/
/*                                                                            */
/*      Control Statements                                                    */
/*                                                                            */
/******************************************************************************/

/* General:
 * Y Insert new line before 'else' if an 'if' statement
 * Y Insert new line before 'catch' in a 'try' statement
 * N Insert new line before 'while' in a 'do' statement
 *
 * 'if else':
 * N Keep 'then' statement on same line
 *   N Keep simple 'if' on one line
 * N Keep 'else' statement on same line
 * Y Keep 'else if' on one line
 */


/*
 * If...else preview
 */

class Example
{
    void bar()
    {
        do
        {
        } while (true);
        try
        {
        } catch (...)
        {
        }
    }
    void foo2()
    {
        if (true)
        {
            return;
        }
        if (true)
        {
            return;
        }
        else if (false)
        {
            return;
        }
        else
        {
            return;
        }
    }
    void foo(int state)
    {
        if (true)
            return;
        if (true)
            return;
        else if (false)
            return;
        else
            return;
    }
};


/******************************************************************************/
/*                                                                            */
/*      Line Wrapping                                                         */
/*                                                                            */
/******************************************************************************/

/* Line width and indentation levels:
 *
 * Maximum line width:                                                80
 * Default indentation for wrapped lines:                              2
 * Default indentation for initializer lists:                          2
 * N Never join already wrapped lines
 *
 * Class declarations:
 *
 *   base-clause:
 *     Line wrapping policy:  Wrap all elements, except first element if not
 *                            necessary
 *       N Force split, even if line is shorter than maximum width
 *     Indentation policy:    Indent on column
 *
 *
 * Function declarations:
 *
 *   Parameters:
 *     Line wrapping policy:  Wrap only when necessary
 *       N Force split, even if line is shorter than maximum width
 *     Indentation policy:    Indent on column
 *
 *   Exception specification:
 *     Line wrapping policy:  Wrap only when necessary
 *       N Force split, even if line is shorter than maximum width
 *     Indentation policy:    Indent on column
 *
 *   Constructor initializer list:
 *     Line wrapping policy:  Do not wrap
 *
 *
 * 'enum' declaration:
 *
 *   Enumerator list:
 *     Line wrapping policy:  Wrap all elements, every element on a new line
 *       N Force split, even if line is shorter than maximum width
 *     Indentation policy:    Default indentation
 *
 *
 * Function calls:
 *
 *   Arguments:
 *     Line wrapping policy:  Wrap only when necessary
 *       N Force split, even if line is shorter than maximum width
 *     Indentation policy:    Indent on column
 *
 *
 * Expressions:
 *
 *   Binary expressions:
 *     Line wrapping policy:  Wrap only when necessary
 *       N Force split, even if line is shorter than maximum width
 *     Indentation policy:    Indent on column
 *
 *   Conditionals:
 *     Line wrapping policy:  Always wrap first element, others when necessary
 *       N Force split, even if line is shorter than maximum width
 *     Indentation policy:    Indent on column
 *
 *   Assignments:
 *     Line wrapping policy:  Wrap only when necessary
 *       N Force split, even if line is shorter than maximum width
 *     Indentation policy:    Default indentation
 *
 *   Initializer list:
 *     Line wrapping policy:  Wrap only when necessary
 *       N Force split, even if line is shorter than maximum width
 *     Indentation policy:    Indent on column
 *
 *   Stream output:
 *     Line wrapping policy:  Wrap only when necessary
 *       N Force split, even if line is shorter than maximum width
 *     Indentation policy:    Indent on column
 *
 *   Member access:
 *     Line wrapping policy:  Do not wrap
 *
 *
 */

/* Line width for preview, 40 characters
                                       |
                                       V
         1         2         3         4         5         6         7         8
....+....0....+....0....+....0....+....0....+....0....+....0....+....0....+....0
*/


/*
 * Base-clause
 */

class Example: public FooClass,
               virtual protected BarClass
{
};


/*
 * Parameters
 */

class Example
{
    void foo(int arg1, int arg2,
             int arg3, int arg4,
             int arg5, int arg6)
    {
    }
};


/*
 * Exception specification
 */

class Example
{
    int foo() throw (FirstException,
                     SecondException,
                     ThirdException)
    {
        return Other::doSomething();
    }
};


/*
 * Constructor initializer list
 */

class Point
{
public:
    Point(double x, double y) :
            x(x), y(y)
    {
    }

private:
    double x;
    double y;
};


/*
 * Enumerator list
 */

enum Example
{
    CANCELLED,
    RUNNING,
    WAITING,
    FINISHED
};


/*
 * Arguments
 */

class Other
{
    static void bar(int arg1, int arg2,
                    int arg3, int arg4,
                    int arg5, int arg6,
                    int arg7, int arg8,
                    int arg9)
    {
    }
};

void foo()
{
    Other::bar(100, 200, 300, 400, 500,
               600, 700, 800, 900);
}


/*
 * Binary expressions
 */

int foo()
{
    int sum = 100 + 200 + 300 + 400 +
              500 + 600 + 700 + 800;
    int product = 1 * 2 * 3 * 4 * 5 * 6 *
                  7 * 8 * 9 * 10;
    bool val = true && false && true &&
               false && true;
    return product / sum;
}


/*
 * Conditionals
 */

int compare(int argument, int argument2)
{
    return argument > argument2 ?
           100000 : 200000;
}


/*
 * Assignments
 */

static char* string =
        "text text text text";
class Example
{
    void foo()
    {
        for (int i = 0; i < 10; i++)
        {
        }
        const char* character_string;
        character_string =
                "text text text text";
    }
}


/*
 * Initializer list
 */

int array[] =
{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
  13, 14, 15, 16, 17 };


/*
 * Stream output
 */

#include <iostream>
#include <iomanip>

using namespace std;

void PrintDate(int year, int month,
               int day)
{
    cout << setfill('0') << setw(4)
         << year << '/' << setw(2)
         << month << '/' << setw(2)
         << day << endl;
}


/*
 * Member access
 */

class TreeNode
{
public:
    TreeNode* getParent();
    TreeNode* getFirstChild();
};

TreeNode* firstUncle(TreeNode& node)
{
    return node.getParent()->getParent()->getFirstChild();
}


/******************************************************************************/
/*                                                                            */
/*      Comments                                                              */
/*                                                                            */
/******************************************************************************/

/* Line comments:
 * Y Preserve white space between code and line comments if possible
 * Minimum distance between code and line comments:                    1
 */

/*
 * Comments
 */

void lineComments()
{
    printf("%d\n", 1234);           // Integer number
    printf("%.5g\n", 12.34);        // Floating point number
}


#endif
