# Write your MySQL query statement below
with CTE as (
 select  employee_id 
    from  Employees where  employee_id   not in   (select  employee_id from Salaries)
         union
     select  employee_id 
         from Salaries  where  employee_id  not in   (select  employee_id from Employees)
     )
   
   select employee_id from CTE  order by  employee_id ;
         
         