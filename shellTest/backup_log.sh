PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
workdir=$(cd $(dirname $0); pwd)
echo $workdir

if [ -d "Log" ]
then
    echo "Directory Log is exist"
else
    echo "Directory Log is not exist"
fi

#file_arr=(DaemonLog.txt SecSysLog.txt SysLog.txt)
#for file in ${file_arr[@]};
#do
#    if [ -f "${file}" ]
#    then
#      > "${file}"
#      echo "clean ${file} success"
#    else
#      echo "${file} is not exist"
#    fi
#done


tar_file_name=`date +%Y%m%d`
echo "$tar_file_name"


function backup_log() {
  echo "backup log"
  file_arr=(DaemonLog.txt SecSysLog.txt SysLog.txt vsftpd.log)
  backup_dir=${workdir}/backup
  if [ ! -d $backup_dir ];
  then
    mkdir $backup_dir
  fi

  if [ ! -d ${workdir}/Log ];
  then
    mkdir ${workdir}/Log
  fi

  for file in ${file_arr[@]};
  do 
    if [ -f "${file}" ];
    then
      cp -rf "${file}" ${workdir}/Log
      continue
    fi
  done

  tar_file_name=`date +%Y%m%d`
  echo "$tar_file_name"
  #tar_res=`tar -cvf ${tar_file_name}.tar ${workdir}/Log`
  if [ -f "$backup_dir/$tar_file_name.tar.gz" ];
  then
    for i in `seq 1 10`
    do
      if [ ! -f $backup_dir/${tar_file_name}_$i.tar.gz ];
      then
        mv $backup_dir/$tar_file_name.tar.gz $backup_dir/${tar_file_name}_$i.tar.gz
        break
      fi
    done
  fi

  cd ${workdir}
  tar_res=`tar -czvf ./backup/${tar_file_name}.tar.gz ./Log`
  if [[ $? = 0 ]];
  then
    echo "backup log success"
  else
    echo "backup log failed"
  fi
}

backup_log






