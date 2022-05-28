CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
        select distinct ralary_rank.salary
      from 
          (select salary
                 , dense_rank() over( order by salary desc) row_num
          from Employee) ralary_rank
      where ralary_rank.row_num = N
  );
END

