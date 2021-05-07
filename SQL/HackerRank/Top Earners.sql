select (months * salary), count(months * salary) as count from employee
group by months * salary
order by months * salary desc limit 1;