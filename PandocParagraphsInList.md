# Pandora's box 
## Or the Mess of Pandoc (implementation of) & Markdown
Note: This text has a follow up on [stackoverflow](https://stackoverflow.com/questions/49712321/pandoc-markdown-multiparagraph-list-with-code-blocks).

Here everything pandoc says about code blocks 
(From  [https://pandoc.org/MANUAL.html#verbatim-code-blocks](https://pandoc.org/MANUAL.html#verbatim-code-blocks)):
```	
    C1) A block of text indented four (4) spaces (or one tab) is treated as verbatim text:
    that is, special characters do not trigger special formatting, and all spaces and 
    line breaks are preserved. The initial (four space or one tab) indentation is not 
    considered part of the verbatim text, and is removed in the output. Note: blank 
    lines in the verbatim text need not begin with four spaces.

    C2) Code blocks must be separated from surrounding text by blank lines.

    C3) Also, pandoc supports fenced code blocks. These begin with a row of three or 
    more tildes (~) or backticks (`) and end with a row of tildes that must be at 
    least as long as the starting row. Everything between these lines is treated as 
    code. 
```	


Everything Pandoc docs say about lists with multiple paragraphs is the following 
(From [https://pandoc.org/MANUAL.html#lists](https://pandoc.org/MANUAL.html#lists)):

```
    L1) A list item may contain multiple paragraphs and other block-level content. 
    However, subsequent paragraphs must be preceded by a blank line and indented 
    to line up with the first non-space content after the list marker (3,4,5...).

    L2) If the second paragraph is a code block is must be indented 8 spaces (8).
    
    L3) Exception: if the list marker is followed by an indented code block, which 
    must begin 5 (5) spaces after the list marker, then subsequent paragraphs must 
    begin two (2) columns after the last character of the list marker.
    
    L4) List items may include other lists. In this case the preceding blank line is 
    optional. The nested list must be indented to line up with the first non-space  
    (3,4,5...) character after the list marker of the containing list item.
```

In parenthesis I have highlighted the different indentation levels that show up in these rules.
How easily can you keep track of all those indentations? Can you find a general guiding idea in
choosing those values?

Have you ever tried to write a list item with 4+ paragraphs one (not the last one) being a code block? Those instructions doesn't seem enough.

It so happens that they are not even correct!

## Test results
Assume a default numbered/ordered list with two items. The list marker extends up to column 2.

The first item's content will start at column 4 (1 white space after list marker)

# L1: This (wrong!):
L1) *A list item may contain multiple paragraphs and other block-level content.
However, subsequent paragraphs must be preceded by a blank line and indented
to line up with the first non-space content after the list marker*.

**This is outright wrong!**

Following L1 above, paragraph 2 from list item 1 must start at column 4.

However, if we test it, it must start at column 6!

Add 1 more column if paragraph 1 starts with italics (i.e., 1st non-space
character is $\, * \,$), or even 2 more columns if par1 starts with boldface (2 asterisks). 

Yet, **this is not exactly what the docs say!**

```
1. List item. Paragraph 1

     Paragraph 2. If start aligned with 'L' above (col 4), this 'P' shows left of 1.
     But all good, if start aligned w/ 's' above (col 6).

   Paragraph 3. Par 3 left of 1. if it starts at col 4, even if Par 2

   Paragraph 4
2. List item
```
## shows as

1. List item. Paragraph 1

     Paragraph 2. If start aligned with 'L' above (col 4), this 'P' shows left of 1.
     But all good, if start aligned w/ 's' above (col 6).

   Paragraph 3. Par 3 left of 1. if it starts at col 4, even if Par 2

   Paragraph 4
2. List item

# L1: This (corrected):
L1) *A list item may contain multiple paragraphs and other block-level content.
However, subsequent paragraphs must be preceded by a blank line and indented
to line up with the ~~first~~ **3rd** non-space content after the list marker*.

That is, 2 more spaces than that first non-space character, or column 4 if numbered list, and 3 if bullet list.

```
1. List item. Paragraph 1

     Paragraph 2. If start aligned with 'L' above (col 4), this 'P' shows left of 1.
     But all good, if start aligned w/ 's' above (col 6).

     Paragraph 3. Par 3 left of 1. if it starts at col 4, even if Par 2 ok. But ok, if starts at 6

     Paragraph 4
2. List item
```
## shows as

1. List item. Paragraph 1

     Paragraph 2. If start aligned with 'L' above (col 4), this 'P' shows left of 1.
     But all good, if start aligned w/ 's' above (col 6).

     Paragraph 3. Par 3 left of 1. if it starts at col 4, even if Par 2 ok. But ok, if starts at 6

     Paragraph 4
2. List item

# L2: This w/ code I (wrong!):
L2) If the second paragraph is a code block is must be indented 8 spaces.

**Outright wrong**: It's enough to indent it 5 spaces so that the start of its first line aligns with
the third character of the start of the previous paragraph, or in other words, indented 1 space
with respect to the first non-space character of the previous paragraph (after the paragraph marker).

However, **nor rule seems to work for following paragraphs** after a code block!!

       1. List item. Paragraph 1
       
       ```javascript
            // Second paragraph is a code block. If start at column 6, code shows ok. 
            // Additional indentation only moves code block further right
            // Notice code block tag/backticks starts at column 1 though!!
            //  If it starts at col 2+, code block w/ tag is messed up as all code block.
            var x = 3
            print( "Pandoc has made a mess out of Markdown!" )
       ```
       
              Paragraph 3. However Par 3 falls off and breaks the list.
       2. List item

## shows as

1. List item. Paragraph 1

```javascript
     // Second paragraph is a code block. If start at column 6-10, code shows ok. 
     // Additional indentation only moves code block further right
     // Notice code block tag/backticks starts at column 1 though!!
     //  If it starts at col 2+, code block w/ tag is messed up as all code block.
     var x = 3
     print( "Pandoc has made a mess out of Markdown!" )
```

       Paragraph 3. However Par 3, if starts col 6 falls off and breaks the list.
2. List item

# L3: This w/ code II (wrong!):
L3) *Exception: if the list marker is followed by an indented code block, which
must begin 5 spaces after the list marker, then subsequent paragraphs must
begin two columns after the last character of the list marker*.

**It doesn't work!**

      1.  
      ```javascript
            // First paragraph is a code block starting at col 7
            // Notice code block tag starts at column 1 though!!
            var x = 3
            print( "Pandoc has made a mess out of Markdown!" )
      ```
      
         Paragraph 2. If Starts at col 4 it shows left of 1. marker!
      
         Paragraph 3. HStarts at col 4
      
      2. List item


## shows as

1.  
```javascript
      // First paragraph is a code block starting at col 7
      // Notice code block tag starts at column 1 though!!
      var x = 3
      print( "Pandoc has made a mess out of Markdown!" )
```

   Paragraph 2. If Starts at col 4 it shows left of 1. marker!

   Paragraph 3. HStarts at col 4

2. List item

# This w/ code III (wrong!):

       1. List item. Paragraph 1
       
            Paragraph 2. If start aligned with 'L' above (col 4), this 'P' shows left of 1.
            But all good, if start aligned w/ 's' above (col 6).
       
            Paragraph 3. Par 3 left of 1. if it starts at col 4, even if Par 2 ok. But ok, if starts at 6
       
       ```javascript
            var x = 3
            print( "Pandoc has made a mess out of Markdown!" )
       ```
       
            Paragraph 4. W/ the previous blank line, Par 4 falls off and breaks the list. Also, if Par 4
            comes right after code -no blank line.
       2. List item

## shows as

1. List item. Paragraph 1

     Paragraph 2. If start aligned with 'L' above (col 4), this 'P' shows left of 1.
     But all good, if start aligned w/ 's' above (col 6).

     Paragraph 3. Par 3 left of 1. if it starts at col 4, even if Par 2 ok. But ok, if starts at 6

```javascript
     var x = 3
     print( "Pandoc has made a mess out of Markdown!" )
```

     Paragraph 4. W/ the previous blank line, Par 4 falls off and breaks the list. Also, if Par 4
     comes right after code -no blank line.
2. List item

# This w/ code IV (wrong!):

       1. List item. Paragraph 1
       
            Paragraph 2. If start aligned with 'L' above (col 4), this 'P' shows left of 1.
            But all good, if start aligned w/ 's' above (col 6).
       
            Paragraph 3. Par 3 left of 1. if it starts at col 4, even if Par 2 ok. But ok, if starts at 6
       
            ```javascript
            var x = 3 //This whole code block including code tag (fence) shows as code.
            print( "Pandoc has made a mess out of Markdown!" )
            ```
       
            Paragraph 4. Par 4 falls off and breaks the list.
       2. List item

## shows as

1. List item. Paragraph 1

     Paragraph 2. If start aligned with 'L' above (col 4), this 'P' shows left of 1.
     But all good, if start aligned w/ 's' above (col 6).

     Paragraph 3. Par 3 left of 1. if it starts at col 4, even if Par 2 ok. But ok, if starts at 6

     ```javascript
     var x = 3 //This whole code block including code tag (fence) shows as code.
     print( "Pandoc has made a mess out of Markdown!" )
     ```

     Paragraph 4. Par 4 falls off and breaks the list.
2. List item

# This w/ code V (wrong!):

       1. List item. Paragraph 1
       
            Paragraph 2. If start aligned with 'L' above (col 4), this 'P' shows left of 1.
            But all good, if start aligned w/ 's' above (col 6).
       
            Paragraph 3. Par 3 left of 1. if it starts at col 4, even if Par 2 ok. But ok, if starts at 6
       
       ```javascript
                var x = 3 //Code block start aligned with 1. and code starts at col 10. Code shows ok!
                print( "Pandoc has made a mess out of Markdown!" )
       ```
       
            Paragraph Par 4 falls off and breaks the list.
       2. List item

## shows as

1. List item. Paragraph 1

     Paragraph 2. If start aligned with 'L' above (col 4), this 'P' shows left of 1.
     But all good, if start aligned w/ 's' above (col 6).

     Paragraph 3. Par 3 left of 1. if it starts at col 4, even if Par 2 ok. But ok, if starts at 6

```javascript
         var x = 3 //Code block start aligned with 1. and code starts at col 10. Code shows ok!
         print( "Pandoc has made a mess out of Markdown!" )
```

     Paragraph 4. Par 4 falls off and breaks the list.
2. List item

# This w/ code VI (wrong!):

       1. List item. Paragraph 1
       
            Paragraph 2. If start aligned with 'L' above (col 4), this 'P' shows left of 1.
            But all good, if start aligned w/ 's' above (col 6).
       
            Paragraph 3. Par 3 left of 1. if it starts at col 4, even if Par 2 ok. But ok, if starts at 6
       
       ```javascript
                //Code block must align w/ 1, but code must start at col 10!
                var x = 3 //This whole code block shows finally as code. But Par 4 falls off list.
                print( "Pandoc has made a mess out of Markdown!" )
       ```
       
          Paragraph 4. Par 4 falls off and breaks the list. Even if starts at col 4!
       2. List item

## shows as

1. List item. Paragraph 1

     Paragraph 2. If start aligned with 'L' above (col 4), this 'P' shows left of 1.
     But all good, if start aligned w/ 's' above (col 6).

     Paragraph 3. Par 3 left of 1. if it starts at col 4, even if Par 2 ok. But ok, if starts at 6

```javascript
         //Code block must align w/ 1, but code must start at col 10!
         var x = 3 //This whole code block shows finally as code. But Par 4 falls off list.
         print( "Pandoc has made a mess out of Markdown!" )
```
   Paragraph 4. Par 4 falls off and breaks the list. Even if starts at col 4!

2. List item
