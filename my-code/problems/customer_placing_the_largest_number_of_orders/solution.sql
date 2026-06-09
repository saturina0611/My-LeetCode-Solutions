select
    o.customer_number
from Orders o
group by o.customer_number
having o.customer_number = 
        (select 
            o2.customer_number
        from Orders o2
        group by o2.customer_number
        order by count(o2.customer_number) desc
        limit 1
        );
        