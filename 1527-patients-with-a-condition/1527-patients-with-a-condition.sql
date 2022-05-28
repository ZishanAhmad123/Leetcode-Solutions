# Write your MySQL query statement below

SELECT *
FROM Patients
WHERE conditions LIKE 'DIAB1%'  #to check whether first condition is diab1
	OR conditions LIKE '% DIAB1%'; #to check if any middle condition has diab1