# choreonoid_ros_khr3
KHR-3HVのロボットモデルを読み込んだプロジェクトとなっており,Meridianプロジェクトの制御ボードMeridian Board Type.KとChoreonoidを連携させるために作成した.


- Meridianの中間まとめ
  
  https://note.com/ninagawa123/n/ncfde7a6fc835

- ChoreonoidはROS用にソースからビルドを行ったものを使用する．
  
  https://choreonoid.org/ja/documents/latest/ros/index.html
  
- Choreonoid連携のために修正を加えたMeridian TWIN

  https://github.com/MasutaniLab/Meridian_TWIN

- Choreonoid連携のために修正を加えたMeridianConsole

  https://github.com/MasutaniLab/Meridian_console
# Choreonoidのプロジェクトの起動方法
下記のコマンドを実行するとKHR-3HVモデルが入ったChoreonoidのプロジェクトが開く
- Terminal 
  ```
  $ roslaunch choreonoid_ros_khr3 bringup_group.launch
  ```
  
# モーションの変換
  Choreonoidで作成したモーションpseqをMeridian Boardで動作させるための形式に変換し,モーションデータは手動でmicroSDに移すことでモーションを再生することができる.
- Termina2 
  ```
  $ cd ~/catkin_ws/src/choreonoid_ros_khr3/project
  $ python3 pseq2txt.py (モーションファイル名)
  ```
