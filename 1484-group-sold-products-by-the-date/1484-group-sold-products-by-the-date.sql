# Write your MySQL query statement below

select sell_date , count( distinct(product))as  num_sold,
  GROUP_CONCAT(distinct product SEPARATOR ',') as products
  from Activities a
    group by sell_date 
     order by sell_date asc
