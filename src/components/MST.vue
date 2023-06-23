<template>
    <el-descriptions title="最小生成树" :column="2">
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

const id = groupList[4].id;
const name = groupList[4].name;

const code = ref('');

onMounted(async () => {
    code.value = await invoke('source', { x: 'mst' });
});
</script>
    
<style></style>