# Visualization-Technology-MFC
Visualization Technology(CS professional elective) programming assignments.The course is mainly about MFC. Taught by Assoc. Prof. Wu Ying. 

## Final Exam

Please use Microsoft Visual Studio 2010 to design an MFC application, the specific requirements are as follows:

### Border window style (a total of 20 points)

[4] The application type is a single document, the project type is MFC standard, and the command bar is a classic menu and a traditional docking toolbar.

[2] The title of the border window is 2022 Final Work-XXX, where XXX is the name.

[1] The maximize button of the border window is set to invalid.

[2] The size of the border window is initialized to 400×400.

[4] Add a menu item Test (T) to the border window menu Help (H), click this menu item to pop up a modal dialog box.

[2] Define the shortcut key Ctrl+Alt+T for the menu item test (T).

[3] Define the toolbar button red font T for the menu item test (T), the mouse stops on the button T. The status bar prompts the dialog box test.

[2] Click the menu item About in the Help (H) menu... A message dialog box pops up, and the content of the static control is modified to Name: XXX and Student ID: XXX.

### View window style (a total of 26 points)

[4] A bitmap is displayed in the view window, with 2022 and visualization, white text on a green background, and the picture is located in the upper right corner of the view window.

[6] Press the N key (case-insensitive), the bitmap moves horizontally to the left (with an amplitude of 20 pixels and a timer interval of 100ms), and finally stops at the upper left corner of the view window.

[4] Output text in the view window, with name: XXX and student ID: XXX, the text color is red, located in the lower left corner of the view window.

[7] Graphics (may be rectangles or ellipses) are displayed in the view window. The initial graphic is an ellipse, the initial position is the center of the view, the size is 100×100, the border width is 3, the border color is RGB(255,0,255), and the fill style is It is a diagonal cross, and the fill color is blue.

[5] The view window has a shortcut menu (aligned to the left): rectangle (R) and ellipse (E), click the menu item rectangle (R) or ellipse (E), the graph will immediately become a rectangle or ellipse, and other attributes of the graph will remain unchanged.

### Dialog style (a total of 38 points).

[1] The dialog title is Dialog Test.

[3] In the border group box, select the border shape (ellipse or rectangle) through the radio button.

[3] In the border group box, select the border color through the check box, there are 8 color combinations.

[4] In the border group box, use the slider to select the border width, the value range is 1 to 6, and the style is cursor up.

[4] In the fill group box, select the fill style (horizontal line, vertical line or diagonal cross line) through the combo box, and prohibit the input of text.

[3] In the fill group box, click the color button to pop up the color dialog box, which is used to modify the fill color of the graph. The initial color of the color dialog box is the fill color in the preview image.

[4] In the information group box, the name and student number are displayed through the edit box, and the input of text is prohibited.

[4] In the coordinate group box, the coordinates of the center point of the view are displayed through the edit box, and the input of text is prohibited.

[4] In the preview group box, display the preview of the graphics in the view window.

[8] After changing any properties (border graphics, border color, border width, fill style or fill color), the preview image is updated immediately.

### Data transfer and save (16 points in total)

[5] Each time the dialog box pops up, the initial value of each control is the graphic properties (including coordinates) in the view window.

[5] Every time you click the OK button to close the dialog box, the graphics in the view window are updated immediately according to the modified properties.

[5] When saving the document, store the graphics properties (including coordinates) in the view window.

[1] When saving a document, the archive file extension is txt.
