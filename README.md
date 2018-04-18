# fdf
#5th project @Ecole42

FDF or 'fil de fer' in French is a little program that displays a topological map in different types of projection.
Projections are
<ol>
	<li> Isometric (by default when you lauch the program), or '2' on your keyboard. </li>
	<li> Front-view, or '1' on your keyboard. </li>
	<li> Orthographic, or '3' on your keyboard. </li>
</ol>

<ul>
<li>Compiling </li>
  <code>make</code>
 <li> Running </li>
  <code> ./fdf ./maps/[map].fdf </code>
 <li>Cleaning</li>
    <code>fclean</code>
 <li>Recompiling</li>
  <code>make re</code>
 </ul>

 You can use maps in the maps folder or create your own. Maps must be square, and the numbers which define the height must be integers. 
You can zoom by using your mouse scroll or with '-' and '+' on your keyboard. 
You can move with the directional keys. 
You can change the height with 'q' to decrease, and 'w' to increase. 
