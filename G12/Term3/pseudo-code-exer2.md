
```
OverallHighest <-- 0
OverallLowest  <-- 100
OverallTotal   <-- 0

FOR Test <-- 1  TO  4
  SubjectHighest <-- 0
  SubjectLowest  <-- 100
  SubjectTotal   <-- 0

  CASE Test OF
    1 : SubjectName <-- "Math"
    2 : SubjectName <-- "Science"
    3 : SubjectName <-- "English"
    4 : SubjectName <-- "IT"
  ENDCASE

  FOR StudentNumber  <-- 1 TO 600
    REPEAT
      PRINT "ENTER Student ", StudentNumber,"'s Mark for ",SubjectName
      INPUT Mark
    UNTIL Mark < 101 AND Mark > -1
  
    IF Mark < OverallLowest THEN OverallLowest <-- Mark
    IF Mark < SubjectLowest THEN SubjectLowest <-- Mark
    IF Mark < OverallHighest THEN OverallHighest <-- Mark
    IF Mark < SubjectHighest THEN SubjectHighest <-- Mark
    OverallTotal <-- OverallTotal + Mark
    SubjectTotal <-- SubjectTotal + Mark
  NEXT

  SubjectAverage <-- SubjectTotal/600

  PRINT SubjectName 
  PRINT "Average : ", SubjectAverage
  PRINT "Highest score : ", SubjectHighest
  PRINT "Lowest score : ", SubjectLowest
NEXT

OverallAverage <-- OverallTotal / 2400

PRINT "OVerall average : ", OverallAverage
PRINT "Overall Highest score : ",OverallHighest
PRINT "Overall Lowest score : ",OverallLowest
```
