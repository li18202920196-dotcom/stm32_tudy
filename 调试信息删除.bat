@echo off
echo ==============================================
echo          Keil 工程一键清理调试文件
echo          安全删除：.o .d .crf .hex .axf 等
echo ==============================================
echo.

:: 开始删除各类非工程文件
echo 正在删除中间文件 (.o .d .crf .lst .map .lnp .dep) ...
del /s /q *.o
del /s /q *.d
del /s /q *.crf
del /s /q *.lst
del /s /q *.map
del /s /q *.lnp
del /s /q *.dep

echo 正在删除输出文件 (.hex .axf .build_log .htm) ...
del /s /q *.hex
del /s /q *.axf
del /s /q *.build_log
del /s /q *.htm

echo 正在删除用户界面配置文件 (.uvguix.*) ...
del /s /q *.uvguix.*

echo 正在删除调试配置文件 (.dbgconf) ...
del /s /q *.dbgconf

echo 正在删除日志与锁文件 (*.log *.lock) ...
del /s /q *.log
del /s /q *.lock
del /s /q keil-assistant.log

echo.
echo ==============================================
echo                清理完成！
echo          所有调试冗余文件已删除
echo ==============================================
echo.
pause