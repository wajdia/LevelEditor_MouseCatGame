Level Editor: Mouse & Cat

Written by: Wajdi Aweida

--------------------
General information:
--------------------
In this app you can edit a board level to be played in Mouse & Cat game
features:
Adding a mouse to the game (single mouse can be added)
Adding static objects like walls, gifts, keys, doors and Cheese
Adding cats

Also you can delete any object from the board by delete button, save the level
to further use, or start editing new board.
Save level works only if the level is valid: containing a mouse & one cheese at least
Note that if there is no previous saved level, or when choosing to start editing
new board, you need to enter the board dimensions in the terminal (Rows Cols).

Important note: notice that your srcreen dimensions are probably 9:16
best boards preview is within this ratio.
Consider Rows:Cols to be as close to 9:16

------
Files:
------
Constants.h
contains app constants (colors, default dimensions,..)

Tile.h
Tile header file

Tile.cpp
Implementation of Tile class

Board.h
Board header file

Board.cpp
Implementation of Board class

Row.h
Row header file

Row.cpp
Implementation of Row class

Button.h
Button header file

Button.cpp
Implementation of Button class

Window.h
Window header file

Window.cpp
Implementation of Window class

main.cpp
Runs the app by calling Window run() function

Images: png files represnting the objects in the game:
Mouse.png
Cat.png
Wall.png
Cheese.png
Gift.png
Door.png
Key.png
Save.png
Delete.png
NewPage.png

----------------
Data structures:
----------------
Row: represent a dynamic array of Tile objects.
support adding objects, check if empty and other methods.

vector: used to represent the board, which consists of vector of Rows

The saved level will be in the format:

ROWS COLS
EEEEEEEEEEE...EE
EEEEEEEEEEE...EE
.
.
.
EEEEEEEEEEE...EE

E for Element.

for example:

11 10
#    #^   
#    ### $
%F $     #
#        #
########D#
# #      #
#        #
#        #
#^  ####D#
## F#***$*
##########

-----------
Algorithms:
-----------
The significant algorithm is to calculate the dimensions of window according to
given board dimensions, the main challenge is to balance the dimensions of 
the board and to keep track the window dimensions.

The main aim here was: to show the whole board without any cut edges.
I think it can be made better and more smarter than I made it,
but I think it's sufficient for user who understand the dimensions of his/her
screen(9:16 or other)and choose ROWS & COLS accordingly.

-----------
Design:
-----------
The main Object Window (in retrospect, I may change the name to Controller), contains
the Board object and array of Button objects which control the board.

Board consists of vector of Rows, each Row represent row of Tiles.

Better design was to use NEW PAGE & SAVE buttons to be inherited from Button class,
but then polymorphism is needed to create the array of the Buttons, which need more
research and study.

-----------
Known bugs:
-----------
Because of the dimensions of standard screens: 9:16
when the number of the rows is big enough, the dimensions of the board may
shrink unexpectedly, although the window got enough space to show a bit 
better board.
 
------------
Other notes:
------------
I noticed that there're some warnings related to Row class.
(which manages dynamic memory)
The compiler is worried about illegal array access.
Board class is made to use Row wisely.