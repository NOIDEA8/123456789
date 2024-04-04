package com.example.app;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.os.Message;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button login = (Button) findViewById(R.id.login);
        EditText account = (EditText) findViewById(R.id.account);
        EditText code = (EditText) findViewById(R.id.code);
        login.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (account.getText().toString().isEmpty()||code.getText().toString().isEmpty()){
                    Toast.makeText(MainActivity.this,"请完整输入信息",Toast.LENGTH_SHORT).show();
                } else if (account.getText().toString().equals("1")&&code.getText().toString().equals("1")) {
                    Toast.makeText(MainActivity.this,"您已成功登录",Toast.LENGTH_SHORT).show();
                    Intent intent=new Intent(MainActivity.this, MessageActivity.class);
                    startActivity(intent);
                    finish();
                } else{
                    Toast.makeText(MainActivity.this,"账号或密码错误",Toast.LENGTH_SHORT).show();
                }
            }
        });
    }
}