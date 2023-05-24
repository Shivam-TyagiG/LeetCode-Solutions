# Write your MySQL query statement below
# select author_id as id
# from Views
# group by author_id
# having author_id = viewer_id;
# order by id in ASC;

SELECT DISTINCT(author_id) AS id 
FROM Views WHERE author_id = viewer_id 
ORDER BY id ASC;