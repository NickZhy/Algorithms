# Write your MySQL query statement below
select Request_at as Day, 
round(sum(case when Status <> 'completed' then 1.0 else 0.0 end) / count(*), 2) as 'Cancellation Rate'
from Trips join Users 
on Client_Id = Users_Id
where (Request_at between '2013-10-01' and '2013-10-03') and
Banned <> 'Yes'
group by Request_at
