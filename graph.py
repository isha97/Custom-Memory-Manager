# code for plotting performance measurement
import matplotlib.pyplot as plt


rtt=[0.07,0.13,0.18,0.24,0.3,0.36]
p=[2,4,6,8,10,12]
bx=plt.subplot(111)
bx.plot(p,rtt,linestyle='--',marker='o',linewidth=1.5)
bx.grid()
bx.set_xlim(0,14)
bx.set_ylim(0,0.40)
bx.set_title('Performance Measurement',color='#000000',weight="bold",size="large")
bx.set_ylabel('Execution Time')
bx.set_xlabel('Number of Memory Allocations and Deallocations (x 10^6)')
bx.text(2,0.34,'Green -- = With Memory Manager\nBlue -- = Without Memory Manager\n',bbox={'facecolor':'white','pad':10})

p=[2,4,6,8,10,12]
rtt=[0.04,0.08,0.11,0.14,0.18,0.22]
bx.plot(p,rtt,linestyle='--',marker='o',linewidth=1.5)

plt.savefig('graph.png')
