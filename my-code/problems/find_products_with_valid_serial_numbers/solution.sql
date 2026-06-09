# Write your MySQL query statement below
select
    *
from products p
where 
    (

    (locate(binary 'SN' , binary p.description) != 0) #substring(p.description, locate(binary 'SN' , binary p.description) , 11)
    and (substring(substring(p.description, locate(binary 'SN' , binary p.description) , 11) , 3 , 1) REGEXP '^[0-9]$')
    and (substring(substring(p.description, locate(binary 'SN' , binary p.description) , 11) , 4 , 1) REGEXP '^[0-9]$')
    and (substring(substring(p.description, locate(binary 'SN' , binary p.description) , 11) , 5 , 1) REGEXP '^[0-9]$')
    and (substring(substring(p.description, locate(binary 'SN' , binary p.description) , 11) , 6 , 1) REGEXP '^[0-9]$')
    and (substring(substring(p.description, locate(binary 'SN' , binary p.description) , 11) , 7 , 1) = '-')
    and (substring(substring(p.description, locate(binary 'SN' , binary p.description) , 11) , 8 , 1) REGEXP '^[0-9]$')
    and (substring(substring(p.description, locate(binary 'SN' , binary p.description) , 11) , 9 , 1) REGEXP '^[0-9]$')
    and (substring(substring(p.description, locate(binary 'SN' , binary p.description) , 11) , 10 , 1) REGEXP '^[0-9]$')
    and (substring(substring(p.description, locate(binary 'SN' , binary p.description) , 11) , 11 , 1) REGEXP '^[0-9]$')
    and (substring(substring(p.description, locate(binary 'SN' , binary p.description) , 12) , 12 , 1) = ' ')
    and (substring(p.description, locate(binary 'SN' , binary p.description) - 1 , 1) = ' ')

    )
order by p.product_id asc;