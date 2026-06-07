select 
    stu.student_id student_id,
    stu.student_name student_name,
    sub.subject_name subject_name,
    count(ex.student_id) attended_exams
from Students stu
cross join Subjects as sub
left join Examinations as ex 
    on stu.student_id = ex.student_id
    and sub.subject_name = ex.subject_name
group by stu.student_id , sub.subject_name
order by stu.student_id;