class BinaryTree {
  constructor(initialValue) {
    this.child = { left: null, right: null };
    if (initialValue) {
      this.value = initialValue;
    }
  }

  insert(item) {
    if (!this.value) {
      this.value = item;
      return;
    }

    this.createNode(
      this.compareNodes(this.value, item) ? "left" : "right",
      item
    );
  }

  search(key) {}

  createNode(target, item) {
    if (!this.child[target]) {
      this.child[target] = new BinaryTree(item);
    } else {
      this.child[target].insert(item);
    }
  }

  compareNodes(a, b) {
    return a > b;
  }

  printPre() {
    process.stdout.write(` ${this.value}`);
    this.child.left && this.child.left.printPre();
    this.child.right && this.child.right.printPre();
  }

  printIn() {
    this.child.left && this.child.left.printIn();
    process.stdout.write(` ${this.value}`);
    this.child.right && this.child.right.printIn();
  }

  printPost() {
    this.child.left && this.child.left.printPost();
    this.child.right && this.child.right.printPost();
    process.stdout.write(` ${this.value}`);
  }
}

function processEntry(input, index) {
  const tree = new BinaryTree();

  input.split(" ").forEach((item) => {
    tree.insert(parseInt(item));
  });

  process.stdout.write(`Case ${index + 1}:\n`);

  process.stdout.write("Pre.:");
  tree.printPre();
  process.stdout.write("\n");

  process.stdout.write("In..:");
  tree.printIn();
  process.stdout.write("\n");

  process.stdout.write("Post:");
  tree.printPost();
  process.stdout.write("\n");
}

main();
function main() {
  const input = require("fs").readFileSync("/dev/stdin", "utf8");
  const lines = input.split("\n");

  const numIterations = lines.shift();

  for (let i = 0; i < numIterations; i++) {
    const _ = lines.shift();
    const line = lines.shift();
    processEntry(line, i);
    console.log("");
  }
}
