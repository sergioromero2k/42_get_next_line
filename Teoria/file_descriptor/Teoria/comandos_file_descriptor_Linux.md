ls /proc/$$/fd - Mostrar todos los descriptores de archivo que tengo.

ps -aux | grep firefox 
- Vemos el proceso
- Cuando sepas el id de proceso, es lo que vamos a necesitar para ver los descriptores de archivo.

ls -la/ proc/62743

exec 5>&1           crear tu propio descriptor de archivo y luego dirigir al 1.
exec 5>command.txt  luego dirigir todo a un archivo de comandos.txt
ls -l /proc/$$/fd   para ver que hace tu descriptor de archivo. y co n 
ps -aux>&5          Dirigira todo al descriptor de archivo.
exec 5>&--          Eliminar descriptor de archivo.
 