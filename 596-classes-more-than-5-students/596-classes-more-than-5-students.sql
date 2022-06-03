# Write your MySQL query statement below

select class from (select class, count(student)as Cnt
  from Courses 
   group by class 
    having Cnt>=5) x
