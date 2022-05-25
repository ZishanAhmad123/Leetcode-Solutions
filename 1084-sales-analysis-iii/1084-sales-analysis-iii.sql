# Write your MySQL query statement below

select p.product_id, p.product_name from
product p where product_id not in (
select product_id from sales s where
sale_date > "2019-03-31"  or  sale_date< "2019-01-01"  );