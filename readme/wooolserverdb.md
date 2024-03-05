# 构建server

## 设置sql_mode(下述方法在当前服务中生效,重启mysql失效)
* start mysql server
* `select @@global.sql_mode;`
* delete NO_ZERO_IN_DATE, NO_ZERO_DATE
* `set global sql_mode = 'STRICT_TRANS_TABLES,ALLOW_INVALID_DATES,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION'`

## 登陆mysql(密码同Mac)
* `mysql -u root -p`

## 创建数据库
* `CREATE DATABASE woool_accountdb;`
* `CREATE DATABASE woool_serverdb;`
* `CREATE DATABASE woool_logdb;`

## 创建表
* `use woool_accountdb; source /Users/zhangfei/code/hoodinn/woool70Server/tools/sql/accountdb_db.sql;`
* `use woool_serverdb; source /Users/zhangfei/code/hoodinn/woool70Server/tools/sql/server_db.sql;`
* `use woool_logdb; source /Users/zhangfei/code/hoodinn/woool70Server/tools/sql/log_db.sql;`

## 初始化表数据
* `use woool_accountdb;`
* `source /Users/zhangfei/code/hoodinn/sql_init/app_info.sql;`
* `source /Users/zhangfei/code/hoodinn/sql_init/ids.sql;`
* `source /Users/zhangfei/code/hoodinn/sql_init/server_info.sql;`
* `source /Users/zhangfei/code/hoodinn/sql_init/union_redis.sql;`

## PS:导出表数据
* `mysqldump -u root -p --databases woool_accountdb --tables app_info > ./code/hoodinn/sql_init/app_info.sql`
* `mysqldump -u root -p --databases woool_accountdb --tables ids > ./code/hoodinn/sql_init/ids.sql`
* `mysqldump -u root -p --databases woool_accountdb --tables server_info > ./code/hoodinn/sql_init/server_info.sql`
* `mysqldump -u root -p --databases woool_accountdb --tables union_redis > ./code/hoodinn/sql_init/union_redis.sql`