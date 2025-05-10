#商品管理系统
import os

users={'admin':'12345','other':'12345'}

pd1={'num':1001,'name':'apple','price':8,'discount':1}
pd2={'num':1002,'name':'pear','price':7,'discount':1}
lis=[pd1,pd2]

def login():#登录
    k=input('enter login name:')
    v=input('password:')
    ret =0
    if (k in users.keys() and v==users[k]):
        ret=1
        print('welcome!',k)
    else:
        print('login name or login password error!')
        # temp=input('do you want retry?(y to retry,others to quit)')#暂未添加非法输入判断
        # if (temp=='y'):
        #     ret=1
        # else:
        #     ret=0
    return ret



def disg():#打印商品列表
    print('_______________________________________________')
    for i in pd1.keys():
        print('{:^10}'.format(i),end=' ')
    print()
    for pd in lis:
        print('{:^10}'.format(pd['num']),end=' ')
        print('{:^10}'.format(pd['name']),end=' ')
        print('{:^10}'.format(pd['price']),end=' ')
        print('{:^10}'.format(pd['discount']))
    print('_______________________________________________')
    return

def dis():#打印主页列表
    print('''
    1:show all goods
    2:add goods 
    3:delete goods
    4:set goods
    q:quit
_______________________________________________''')
    return 1

def addg():#添加商品
    gname=input('please enter goods name:')
    gprice=float(input('please enter goods price:'))
    gdiscount=float(input('please enter goods discount:'))    
    lis.append({'num':1001+len(lis),'name':gname,'price':gprice,'discount':gdiscount})
    print('success!')
    # for temp in lis:
    #     if temp['num'] ==gnum:
    #         lis.removw(temp)
    #         # chg=input('enter change key(price,discount):')
    #         # chgn=int(input('you want change to:'))
    #         # temp[chg]=chgn
    #         print('change success!\n')
    #     else:
    #         print('enter error,re...')
    disg()
    return

def delg():#删除商品
    gnum=int(input('please enter you want delete goods number:'))
    ret=0
    for temp in lis:
        if temp['num'] ==gnum:
            lis.remove(temp)
            # chg=input('enter change key(price,discount):')
            # chgn=int(input('you want change to:'))
            # temp[chg]=chgn
            print('change success!\n')
            ret=1
    if(ret==0):
        print('there is no {},re...'.format(gnum))
    disg()
    return

def modifyg():#修改商品参数
    gnum=int(input('please enter goods number:'))
    ret=0
    for temp in lis:
        if temp['num'] ==gnum:
            print(temp)
            chg=input('enter change key(price or discount):')
            chgn=int(input('you want change to:'))
            temp[chg]=chgn
            print('change success!\n')
            ret=1
    if(ret==0):
        print('there is no {},re...'.format(gnum))
    disg()
    return

print(len(lis))

print('system start...')

while(login()):
    #while((ipt=input('enter to operate("q" to quit):'))!='q'):
    #while(ipt = input('enter to operate("q" to quit):'))):
    while(dis()):
        ipt = input('enter to operate(1,2,3,4 or "q" to quit):')
        if(ipt=='q'):
            break
        elif(ipt=='1'):
            disg()
            continue
        elif(ipt=='2'):
            addg()
            continue
        elif(ipt=='3'):
            delg()
            continue
        elif(ipt=='4'):
            modifyg()
            continue
        else:
            print('enter error,re...')
        os.system('pause')
    if(input('do you want exit?(y to quit,others to retry):')=='y'):#暂未添加非法输入判断
    #if(input('you want exit?(y/n):')):
        break

print('system done!')