
# VIM
## Command Mode

### Insertion

- **o -> To Enter a new line and enter into insert mode.**

- **a -> Insert after cursor.**

- i -> Insert before cursor.

- **A -> Insert at the beginning of the line**

- **I -> Insert at the end of the line.**

- **C -> Delete till end of the line and start typing.**

- **>> / << -> Shift right and left.**

- **n>> / n<< -> Shift n lines left or right**

- **cc -> Delete entire line and start typing.**

- ~ -> Switch case and advance cursor.

- s -> Delete the character under the cursor and start typing.


### Text Objects
- Need to look into this.


### Search and Replace

- /s -> Search for s.

- n or N -> Search forward or back for the last search.

 - use * or # -> Search forward or back for the word under cursor.

- :%s/f/t/gc -> Substitute f by t globally and confirm.

### Deletion

- x -> Delete the character under the cursor.

- D -> Delete till end of line.

- **daw -> Delete till word at the cursor.**
- **di' - delete all inside quotes**

- dd -> Delete entire line.


### Movement

- **% -> Match the corresponding bracket.**

- w/b -> Move next word/token right/left.

- **{} -> Beginning or end of paragraph.**

- **0/$ -> Hard Beginning or end of the line**

- **^ -> Soft beginning of the line.**

- G -> end of the page.

- gg -> beginning of the page.

- n% -> nth percentage of the page. 

- **Ctrl + E/Y -> Scroll line up and down.**

- **PageUp /PageDown -> Scroll page up and down.**
 
### Multiple Files

- **:e filepath -> to edit another file.**
- **:ls -> list all the opened files in buffer.**
- **:b buffer_number/file_path -> to open that file and start editing.**

### Split window.

- **:split file_name -> split horizontally.**

- **:vsplit file_name -> split vertically.**

- **Ctrl+w then up/down/left/right -> go to the up/down/left/right window.**

- **Ctrl+w then _ ->maximize current window.**

- **:hide -> hide current window.**

- **:show -> show current window.**

- **:ls -> list all the opened files in buffer.**

- **:b buffer_number/file_path -> to open that file and start editing.**

- **:only -> show only the current window.**
  
### Registers
- "+r+p -> Print the rth register.
- "+r+dd -> Delete the text and keep it in rth register.
- **"+r+y -> Yank the text and keep it in rth register.**
- **:reg -> Show contents of all registers.**

## Insert Mode
- **Ctrl +W -> Delete text before cursor.**
- **Ctrl + K -> Delete text after cursor.**
- **Ctrl + U -> Delete all inserted character in current line.**
- **Ctrl + D/T -> Shift line left or right.**
- Ctrl + X then Ctrl + E/Y -> Scroll up or down.
- Ctrl + N -> Text Completion.
- Ctrl + A -> Inserts Previous Inserted Text.
- **Ctrl + R + n -> Paste the content in nth register.**

## Visual Mode
- v,Ctrl+v,Shift + v -> normal visual,blockstyle, line style.
- o -> go to the other end of selection.

## Cheat Sheet
![vim cheat sheet](./vi-vim-cheat-sheet.gif)