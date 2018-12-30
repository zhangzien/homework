* 假设洗衣机可执行的基本操作如下：<br>
waterinswitch(openclose) // open 打开上水开关， close关闭 wateroutswitch(openclose) // open 打开排水开关， close关闭 getwatervolume() //返回洗衣机内部水的高度 **motorrun(direction) *// 电机转动。 left左转， right右转， stop停 timecounter() // 返回当前时间计数，以秒为单位 *halt(returncode) **//停机， success 成功 failure 失败
* 使用伪代码分解“正常洗衣”程序的大步骤。包括注水、浸泡等
set the water in >> soap the clothes >> wash the clothes >> dewatering the clothes >> stop the work
注水 >> 浸泡 >> 洗涤和漂洗 >> 脱水 >> 停机
* 进一步用基本操作、控制语句（IF、 FOR、 WHILE等）、变量与表达式，写出每 个步骤的伪代码
注水：
turn on the water_in_switch<br>
set the water volume<br>
while(water_input is less than the water volume)<br>
keep the water_in_switch open<br>
while(water_input is more than the water volume or volume timeout)<br>
stop input water<br>
浸泡<br>
set the soaping time<br>
for(set the left time is zero ;the left time is less than the setting time; increase the left time)<br>
keep the clothes soaping<br>
if(the left time is equal to the setting time)<br>
begin to wash<br>
洗涤和漂洗<br>
set the washing times to 3<br>
set the washing time to 20<br>
for(set a to zero; a is less than setting times; add 1 to a;)<br>
if(the washing times is not the 1st time)<br>
pouring the water<br>
pouring in the new and clean water<br>
do<br>
washing and motor runs<br>
while(the pass time is less than the washing time)<br>
pouring the water<br>
脱水<br>
set the motor run's frequency<br>
set the running time<br>
while the past time is less than the running time<br>
keep the motor running in the setting frequency<br>