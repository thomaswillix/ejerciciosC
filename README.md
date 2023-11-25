# These are some exercises about processes done in C. #

I have more programs about processes in my 
<a href="https://github.com/thomaswillix/Processes">Java-Exercises repo :)</a>

## What have I done for now? ##
*Important! all programs have been done in Ubuntu, so urls and reading/writing is different from Windows or MAC*
- <a href="https://github.com/thomaswillix/ejerciciosC/psforkarbol.c">psforkarbol.c</a> creates 5 child processes
of a parent using the fork() function.
- <a href="https://github.com/thomaswillix/ejerciciosC/EjercicioVocales.c">EjercicioVocales.c</a> creates 5 child processes
of a parent using the fork() function and then uses each one of these childs to read from a file and each one of them counts
one vowel and using a pipe() function this number of vowels is tossed to the parent, who receives each number of times that
each one of the vowels appeared and sums the ammount of vowels that appear in the document.
- <a href="https://github.com/thomaswillix/ejerciciosC/EjercicioSenial.c">EjercicioSenial.c</a> is a program that
by signals, reads answers to a question that's been made in the main method and if in 30 seconds the question hasn't been
resolved correctly, a fuction called "destruir()" starts and "destroys" all of the data of your disk (of course that doesn't
happen). If the question is responded correctly, the program is killed.
