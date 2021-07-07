<?php
    include('path.php');
    include(ROOT_PATH . '/app/database/db.php');
    if(isset($_POST['comment'])&& $_POST['postid']&&$_POST['username']){
        $comment = htmlspecialchars($_POST['comment']);
        $postid = $_POST['postid'];
        $username = $_POST['username'];
        if($comment!==""){
            if(selectOne("users",['username'=>$username])!=="" && selectOne("posts",['id'=>$postid])!==""){
                $conn = new mysqli("localhost","root","","blog");
                $stmt = $conn->prepare("INSERT INTO `comments`(`post_id`, `comment`, `username`) VALUES (?, ?, ?)");
                $stmt->bind_param("sss",$postid, $comment, $username);
                $stmt->execute();
                $stmt->close();
                $conn->close();
            }
        }
    }
    
    