#!/usr/bin/env zx
$.verbose = false

let [program, input, output, debug] = process.argv.slice(3);

let inputs = await $`ls ${input}`;
let inputFiles = inputs.toString().split('\n');

let counter = 0;
let all = 0;
for (let file of inputFiles) {
    if (!file.endsWith('.in')) continue;
    const calcResult = (await $`./cmake-build-debug/${program} < ${input}/${file}`).toString().trim();
    const expectedResult = (await $`cat ${output}/${file.replace('in', 'out')}`).toString().trim();

    if (debug) {
        console.log("my: ", calcResult, "should be: ", expectedResult);
    }
    if (calcResult === expectedResult) {
        console.log(`${file}: GOOD`);
        counter++;
    } else {
        console.log(`${file}: BAD`);
    }
    all++;
}

console.log(`Good ${counter} of ${all}`)

