select
    cus.customer_id
from Customer cus
group by cus.customer_id
having count(distinct cus.product_key) = (select COUNT(*) from Product);