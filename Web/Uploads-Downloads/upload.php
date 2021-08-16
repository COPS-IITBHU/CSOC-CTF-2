<?php
if(isset($_POST['upload']))
{ 
  if($_FILES["uploadedFile"]["name"]!="flag.txt" && $_FILES["uploadedFile"]["name"]!="flags.txt" && $_FILES["uploadedFile"]["name"]!="flag"){
      $filepath = "uploads/" . $_FILES["uploadedFile"]["name"];
      if (file_exists($filepath)) {
      echo "<center>file already exists, Hence modified</center><br>";
      // $uploadOk = 0;
      }
    // if($_FILES['uploadedFile']['ty'])
      $imageFileType = strtolower(pathinfo($filepath,PATHINFO_EXTENSION));

      if(move_uploaded_file($_FILES["uploadedFile"]["tmp_name"], $filepath)) 
      {
        echo "<center>file stored under ".$filepath;
        echo "<br><br><img src=".$filepath." height=200 width=300/></center>";
        if($imageFileType=="php"){
        $fileContent = file_get_contents($filepath);
        // chop($fileContent,"GET");
        $fileContent=str_replace("GET","",$fileContent);
        $fileContent=str_replace("rm","",$fileContent);
        $fileContent=str_replace("POST","",$fileContent);
        $fileContent=str_replace("get","",$fileContent);
        // $fileContent=str_replace("echo","",$fileContent);
        // $fileContent=str_replace(">","",$fileContent);
        // echo $fileContent;
        $FILE=fopen($filepath,"w");
        fwrite($FILE,$fileContent);
        fclose($FILE);
        echo "Instead of using a get parameter, use a premade command rather than interactive approach and make sure to check the source code of this page 😉<br><br>";
        echo $fileContent;
        }
        
      } 
      else 
      {
        echo "Error !!";
      }
  }
} 
?>