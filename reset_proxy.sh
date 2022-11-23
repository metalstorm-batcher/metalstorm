sudo ps -ef | grep proxysql | awk '{print $2}' | xargs kill -9
sleep 2
sudo pkill -f proxysql
sleep 2
sudo proxysql
sleep 2
sudo service proxysql start
