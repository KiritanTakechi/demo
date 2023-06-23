<template>
    <el-descriptions title="哈夫曼树" :column="2">
        <el-descriptions-item label="学号">
            {{ id }}
        </el-descriptions-item>
        <el-descriptions-item label="姓名">
            {{ name }}
        </el-descriptions-item>
    </el-descriptions>
    <highlightjs language="cpp" :code=code />
</template>
    
<script setup lang='ts'>
import { onMounted, ref } from 'vue';
import groupList from '../data'
import { invoke } from '@tauri-apps/api';

const id = groupList[2].id;
const name = groupList[2].name;

const code = ref('');

onMounted(async () => {
    code.value = await invoke('source', { x: 'huffman_tree' });
});
</script>
    
<style></style>