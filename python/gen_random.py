import numpy as np
import matplotlib.pyplot as plt
from matplotlib import animation
from mpl_toolkits.mplot3d import Axes3D

# ==================== 参数配置 ====================
a = 0.6
u_range = np.linspace(0, 2 * np.pi, 80)
v_range = np.linspace(0, np.pi, 80)
speed = 0.025
cmap = plt.cm.rainbow
color_shift = True

# ==================== 生成心形曲面 ====================
def heart_surface(a, u, v):
    U, V = np.meshgrid(u, v)
    sinV = np.sin(V)
    cosV = np.cos(V)
    sinU = np.sin(U)
    cosU = np.cos(U)
    X = a * sinV * (15*sinU - 4*np.sin(3*U))
    Y = a * (8*cosV - 5)
    Z = a * sinV * (15*cosU - 5*np.cos(2*U) - 2*np.cos(3*U) - np.cos(4*U))
    return X, Y, Z

X, Y, Z = heart_surface(a, u_range, v_range)

# ==================== 创建图形 ====================
fig = plt.figure(figsize=(8, 8))
ax = fig.add_subplot(111, projection='3d')
ax.set_xlim(-2.5, 2.5)
ax.set_ylim(-2.5, 2.5)
ax.set_zlim(-2.5, 2.5)
ax.set_axis_off()
ax.set_facecolor('black')

# 初始绘制（占位）
surf = ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap=cmap,
                        linewidth=0, antialiased=True)

# ==================== 控制变量 ====================
pause = False   # 暂停标志（全局）

# ==================== 更新函数 ====================
def update(frame):
    global surf, pause
    if pause:
        # 暂停状态：不更新旋转，直接返回当前图形
        return surf,

    theta = frame * speed
    cos_t = np.cos(theta)
    sin_t = np.sin(theta)

    X_rot = X * cos_t + Z * sin_t
    Y_rot = Y
    Z_rot = -X * sin_t + Z * cos_t

    ax.clear()
    ax.set_xlim(-2.5, 2.5)
    ax.set_ylim(-2.5, 2.5)
    ax.set_zlim(-2.5, 2.5)
    ax.set_axis_off()
    ax.set_facecolor('black')

    if color_shift:
        color_offset = frame * 0.008
        colors = cmap((np.linspace(0, 1, X.shape[0] * X.shape[1]) + color_offset) % 1)
        surf = ax.plot_surface(X_rot, Y_rot, Z_rot, rstride=1, cstride=1,
                               facecolors=colors.reshape(X.shape[0], X.shape[1], 4),
                               linewidth=0, antialiased=True)
    else:
        surf = ax.plot_surface(X_rot, Y_rot, Z_rot, rstride=1, cstride=1,
                               cmap=cmap, linewidth=0, antialiased=True)

    ax.text2D(0.02, 0.95, f"Frame: {frame}", color='white', transform=ax.transAxes)
    return surf,

# ==================== 键盘事件 ====================
def on_key(event):
    global pause
    if event.key == ' ':
        pause = not pause
        print("⏸️ 暂停" if pause else "▶️ 继续")
    elif event.key == 'q':
        print("👋 退出")
        plt.close(fig)

fig.canvas.mpl_connect('key_press_event', on_key)

# ==================== 创建动画（移除 pause 参数） ====================
ani = animation.FuncAnimation(fig, update, frames=np.arange(0, 10000),
                              interval=20, blit=False, repeat=True)

# ==================== 运行提示 ====================
print("💖 3D旋转爱心动画")
print("按 空格键 暂停/继续")
print("按 q 键 退出")

plt.show()