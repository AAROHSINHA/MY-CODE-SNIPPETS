SELECT * FROM customers;
SELECT * FROM orders;
SELECT * FROM order_items;

ALTER TABLE orders
RENAME COLUMN order_data TO order_date;

# 1
SELECT cust.name, SUM(ord.amount) AS amount
FROM customers cust JOIN orders ord
ON (cust.customer_id = ord.customer_id)
WHERE ord.order_date BETWEEN CURRENT_DATE - INTERVAL '450 days' AND CURRENT_DATE
GROUP BY cust.name
ORDER BY amount DESC LIMIT 5;

# 2
SELECT cust.name, COUNT(ord.customer_id) AS orders_count
FROM customers cust JOIN orders ord
ON (cust.customer_id = ord.customer_id)
GROUP BY cust.name
HAVING SUM(CASE WHEN ord.status = 'Delivered' THEN 1 ELSE 0 END) > 1;

# 3
WITH monthly_sales AS (
    SELECT 
        DATE_TRUNC('month', ord.order_date) AS month,
        prod.product_name,
        SUM(prod.quantity) AS total_quantity
    FROM orders ord
    JOIN order_items prod ON ord.order_id = prod.order_id
    WHERE EXTRACT(YEAR FROM ord.order_date) = 2024
    GROUP BY DATE_TRUNC('month', ord.order_date), prod.product_name
),
ranked AS (
    SELECT 
        month,
        product_name,
        total_quantity,
        ROW_NUMBER() OVER(
            PARTITION BY month 
            ORDER BY total_quantity DESC
        ) AS rank_in_month
    FROM monthly_sales
)
SELECT *
FROM ranked
WHERE rank_in_month <= 3;

# 4.
WITH monthly_data AS (
	SELECT DATE_TRUNC('month', order_date) AS months,
	SUM(CASE WHEN status = 'Shipped' THEN 1 ELSE 0 END) AS shipped_orders,
	SUM(CASE WHEN status = 'Delivered' THEN 1 ELSE 0 END) AS delivered_orders
	FROM orders
	GROUP BY DATE_TRUNC('month', order_date)
) 
SELECT EXTRACT(MONTH from months) as month_number, shipped_orders, delivered_orders
FROM monthly_data
ORDER BY months;

# 5.
WITH january_customers AS (
	SELECT cust.name, MIN(EXTRACT(MONTH FROM ord.order_date)) AS january
	FROM customers cust JOIN orders ord
	ON (cust.customer_id = ord.customer_id)
	GROUP BY cust.name
), 
september_customers AS (
	SELECT cust.name,
	MAX(CASE WHEN EXTRACT(MONTH FROM ord.order_date) = 9 THEN 9 ELSE 0 END) AS september
	FROM customers cust JOIN orders ord
	ON (cust.customer_id = ord.customer_id)
	GROUP BY cust.name
) 
SELECT janc.name
FROM january_customers janc JOIN september_customers sepc
ON (janc.name = sepc.name)
WHERE janc.january = 2 AND sepc.september = 9;

# 6.
SELECT 
    oi.order_id,
    SUM(oi.quantity) AS total_items,
    SUM(oi.quantity * oi.price_per_unit) AS total_amount
FROM order_items oi
GROUP BY oi.order_id
HAVING SUM(oi.quantity) > 5
   AND SUM(oi.quantity * oi.price_per_unit) > 1000;


# 7
WITH order_cities AS (
	SELECT cust.city, ord.amount
	FROM customers cust JOIN orders ord
	ON (cust.customer_id = ord.customer_id)
)
SELECT city, ROUND(AVG(amount), 2)
FROM order_cities
GROUP BY city;

# 8
SELECT
    cust.customer_id,
    cust.name,
    ord.order_date,
    ord.amount,
    SUM(ord.amount) 
        OVER (
            PARTITION BY cust.customer_id
            ORDER BY ord.order_date
            ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW
        ) AS cumulative_spending
FROM customers cust
JOIN orders ord
    ON cust.customer_id = ord.customer_id
ORDER BY cust.customer_id, ord.order_date;


