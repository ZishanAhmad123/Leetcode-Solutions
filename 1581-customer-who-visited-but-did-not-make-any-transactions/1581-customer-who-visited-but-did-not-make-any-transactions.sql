# Write your MySQL query statement below

select v.customer_id , count( (v.visit_id)) as count_no_trans 
 from Visits v
    where
      v.visit_id not in (select visit_id from Transactions )                      
         group by v.customer_id 
                             
              