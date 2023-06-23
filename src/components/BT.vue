<template>
    <el-descriptions title="二叉树及其遍历" :column="2">
        <el-descriptions-item label="学号">
            {{ id }}
        </el-descriptions-item>
        <el-descriptions-item label="姓名">
            {{ name }}
        </el-descriptions-item>
    </el-descriptions>
    <highlightjs language="cpp" :code=code />
    <el-input v-model="input" :autosize="{ minRows: 8 }" type="textarea" placeholder="请输入测试样例" />
    <el-divider />
    <el-button-group>
        <el-button type="primary" @click="submit">提交</el-button>
        <el-button type="danger" @click="clear">清空</el-button>
    </el-button-group>
    <el-divider />
    <el-card>
        <pre>{{ message }}</pre>
    </el-card>
</template>
    
<script setup lang='ts'>
import { onMounted, ref } from 'vue';
import groupList from '../data'
import { invoke } from '@tauri-apps/api';

const id = groupList[4].id;
const name = groupList[4].name;

const code = ref('');

onMounted(async () => {
    code.value = await invoke('source', { x: 'bt' });
});

const input = ref('');
const message = ref('');

const submit = async () => {
    message.value = await invoke<string>('run', { x: 'bt', input: input.value })
}

const clear = async () => {
    input.value = await '';
    message.value = await '';
}
</script>
    
<style></style>