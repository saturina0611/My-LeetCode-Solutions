
select
    t1.id,
    case 
        when t1.p_id IS NULL then "Root"
        when 
            count(t2.id) > 0
            then "Inner"
        else "Leaf"
    end as type
from Tree t1
left join Tree t2 on t1.id = t2.p_id
group by t1.id, t1.p_id
