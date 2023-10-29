-- Active: 1697956955325@@127.0.0.1@3306

WITH previous_result AS (
    SELECT groups_submit_dates.project_id AS 'project_ID',
        groups_submit_dates."group_ID" AS 'group_ID', 
        CASE 
            WHEN DATE(groups_submit_dates.group_submit_date) <= DATE(projects.due_date) THEN 'ON TIME'
            WHEN DATE(groups_submit_dates.group_submit_date) > DATE(projects.due_date) THEN 'LATE'
            WHEN DATE('now') > DATE(projects.due_date) THEN 'LATE'
            ELSE 'UNDEFINED'
        END AS 'submission_status'
    FROM groups_submit_dates
    INNER JOIN projects ON groups_submit_dates.project_id = projects.id
)
SELECT previous_result.'Project_ID', 
    groups.id AS 'Group_ID', 
    groups.group_name,
    previous_result.'submission_status'
FROM "groups"
INNER JOIN previous_result ON previous_result.'project_ID' = "groups".id
ORDER BY 1;