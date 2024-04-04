package com.example.savetest;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class MainActivityForFile extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button save=(Button) findViewById(R.id.save);
        Button load=(Button) findViewById(R.id.load);
        save.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                save();
            }
        });
        load.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(MainActivityForFile.this,load(),Toast.LENGTH_SHORT).show();
            }
        });
    }
    public void save(){
        String data="Be strong";
        FileOutputStream out= null;
        BufferedWriter writer=null;
        try{
            out=openFileOutput("data", Context.MODE_PRIVATE);
            writer=new BufferedWriter(new OutputStreamWriter(out));
            writer.write(data);//正式将data写入文件
        }catch(IOException e){
            e.printStackTrace();
        }finally{
            try{
                if(writer!=null){
                    writer.close();//关闭写入对象
                }
            }catch(IOException e){
                e.printStackTrace();
            }
        }//这里写一下TryCatch，这个代码块就是拿来做预防的，try出错执行catch，try不出错catch不执行，finally无论如何都会执行， e.printStackTrace();打印堆栈信息。
    }
    public String load(){
        FileInputStream in= null;
        BufferedReader reader=null;
        StringBuilder content=new StringBuilder();
        try{
            in=openFileInput("data");//data是文件名
            reader=new BufferedReader(new InputStreamReader(in));
            String line="";
            while((line=reader.readLine())!=null){
                content.append(line);
            }
        }catch(IOException e){
            e.printStackTrace();
        }finally{
            try{
                if(reader!=null){
                    reader.close();
                }
            }catch(IOException e){
                e.printStackTrace();
            }
        }
        return content.toString();//以字符串的形式返回文件中的内容
    }
}