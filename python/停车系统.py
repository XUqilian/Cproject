import datetime

cnt=10
i=0
dit={}

while 1:
    cnum = input('输入车牌:')            # 车牌自动识别接口获取车牌cnum
    item=dit.get(cnum)
    if(item):                           #字典内有该键
                                        #datetime-item获取停车时间结算
        t=datetime.datetime.now()
        tt=t.timetuple()
        m=30                            #懒了，不想再嵌套算31和32天了
        if(tt[1]==2):
            m=28
            if (tt[0]%4==0):
                m=29
        
                                        #每小时1元吧
        t2=(t-dit[cnum]).seconds
        price=t2*1/3600

        #t1=datetime.datetime(dit[cnum])-datetime.timedelta(t)
        #t2=t1.timetuple()              #'datetime.timedelta' object has no attribute 'timetuple'
        #price=t2[3]+t2[2]*24+t2[1]*24*m+t2[0]*24*365

        i-=1

        print('本次停车时间为'+str(int(price))+'小时,欢迎下次光临！')

        del dit[cnum]

    elif((cnt-i)!=0):                   #字典没有该键并且字典没满
        dit[cnum]=datetime.datetime.now()
        i+=1
        print('欢迎!入场时间:',dit[cnum])

    else:                               #字典满了
        print('车位已满。')