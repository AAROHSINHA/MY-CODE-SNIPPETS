// Define your stopwords list
const feedback_texts = [
  "amazing app!! super easy to use 😍",
  "total waste of time, dont download",
  "works fine for me, no crashes so far",
  "wtf is this, nothing loads 😤",
  "love the new update ❤️❤️",
  "pls fix the login bug asap",
  "this app scammed me. lost my money!",
  "pretty decent, could be faster tho",
  "awesome service!! will recommend to friends",
  "too many ads... like every 10 seconds omg",
  "I thought it was fake but it's actually good lol",
  "never got my order!! support is useless",
  "super clean design, 10/10",
  "BROOO this thing doesn’t even open",
  "meh. not bad, not great either",
  "worst experience ever",
  "excellent interface and smooth transitions",
  "ok ok. works, but not very fast",
  "thanks for fixing the bugs 💪",
  "im not sure if it even does what it says",
  "good value for money 👌",
  "pls refund me i didnt mean to buy",
  "i keep getting error 403 every time",
  "fake app dont trust these people!!!",
  "i like the layout but the color hurts my eyes",
  "worked fine yesterday now it’s broken",
  "great for small businesses",
  "bruh it’s stuck on loading screen again",
  "happy with the update 👍",
  "super laggy on my phone",
  "downloaded for free coins got nothing 😭",
  "thank u for the new dark mode",
  "terrible. ads and bugs everywhere",
  "i literally got a virus from this link",
  "best app ive used this year",
  "it’s okay, but features missing",
  "please stop sending me notifications 😒",
  "5 stars easily. no complaints",
  "looks sketchy af",
  "support replied fast. thanks!",
  "idk why people hate it, works fine",
  "cant even signup. fix your servers!",
  "big thumbs up 👍👍",
  "i love the simplicity of it",
  "doesn’t even load the homepage",
  "garbage app. full of errors",
  "it helped my business a lot!!",
  "wtf fake giveaway link again",
  "so far so good 💯",
  "does not work as advertised",
  "nice features but expensive",
  "give me my cashback or i’m reporting",
  "i wish i could rate 0 stars",
  "superb customer support 👏",
  "download now free bonus limited offer!!!",
  "why tf is this 2GB???",
  "super intuitive and fast",
  "the ads literally block buttons 😭",
  "cant connect to my account anymore",
  "love love love it ❤️",
  "bro fix your server or delete the app",
  "crashes every 2 minutes",
  "idk feels kinda scammy",
  "amazing performance on low end phone",
  "pls add multi language support",
  "i regret installing this junk",
  "good but consumes too much battery",
  "the update ruined everything 😡",
  "wow, way better than i expected",
  "keeps saying 'try again later'",
  "love the support team they’re so nice",
  "fake reviews everywhere lol",
  "worth every penny 💰",
  "it’s full of popups and spammy ads",
  "wouldn’t recommend tbh",
  "i just wanted to test it, stop emailing me",
  "super responsive UI",
  "bro this app cooked my cpu 💀",
  "really useful for my store",
  "login works now yayy",
  "they stole my data do not use",
  "been using for 6 months no issues",
  "pls make a lite version",
  "terrible ui who designed this",
  "couldn’t even verify my email",
  "legit service. got my code instantly",
  "got charged twice. help!",
  "you guys fixed it so fast, respect 🙏",
  "ughh still same bug since june",
  "good app, bad support team",
  "stop scamming ppl with 'free offers'",
  "very slow but usable",
  "hands down best thing on play store",
  "doesn’t save my progress 😭",
  "10/10 experience would use again",
  "super sketchy website link inside??",
  "fine for now. will update review later",
  "thanks team for quick fix",
  "this is fake af don’t click any links",
  "so smooth i love it 😍",
  "cant believe it actually works wow",
  "literally useless app",
  "brilliant update guys 🙌",
  "hate the new interface, go back pls",
];
const stopwords = [
  // Articles
  "a",
  "an",
  "the",

  // Pronouns
  "i",
  "if",
  "you",
  "he",
  "she",
  "it",
  "we",
  "they",
  "me",
  "him",
  "her",
  "us",
  "them",
  "my",
  "your",
  "his",
  "her",
  "its",
  "our",
  "their",
  "mine",
  "yours",
  "hers",
  "ours",
  "theirs",

  // Prepositions
  "about",
  "above",
  "across",
  "after",
  "against",
  "along",
  "among",
  "around",
  "at",
  "before",
  "behind",
  "below",
  "beneath",
  "beside",
  "between",
  "beyond",
  "by",
  "down",
  "during",
  "except",
  "for",
  "from",
  "in",
  "inside",
  "into",
  "like",
  "near",
  "of",
  "off",
  "on",
  "onto",
  "out",
  "outside",
  "over",
  "past",
  "since",
  "through",
  "throughout",
  "till",
  "to",
  "toward",
  "under",
  "until",
  "up",
  "upon",
  "with",
  "within",
  "without",

  // Conjunctions
  "and",
  "but",
  "or",
  "nor",
  "for",
  "yet",
  "so",
  "although",
  "because",
  "since",
  "unless",

  // Auxiliary verbs
  "am",
  "is",
  "are",
  "was",
  "were",
  "be",
  "been",
  "being",
  "have",
  "has",
  "had",
  "having",
  "do",
  "does",
  "did",
  "doing",
  "will",
  "would",
  "shall",
  "should",
  "may",
  "might",
  "must",
  "can",
  "could",

  // Other common words
  "all",
  "any",
  "both",
  "each",
  "few",
  "more",
  "most",
  "other",
  "some",
  "such",
  "no",
  "nor",
  "not",
  "only",
  "own",
  "same",
  "so",
  "than",
  "too",
  "very",
  "just",
  "now",
];
function removeStopwords(tokens) {
  return tokens.filter((token) => !stopwords.includes(token.toLowerCase()));
}
function lower(tokens) {
  return tokens.map((token) => token.toLowerCase());
}
const preprocess = (sentences) => {
  let new_sentences = [];
  for (let sentence of sentences) {
    let tokens = sentence.split(" ");
    tokens = lower(tokens);
    tokens = removeStopwords(tokens);
    new_sentences.push(tokens);
  }
  return new_sentences;
};

const feedbacks = preprocess(feedback_texts);

// TF-IDF
let words = [];
for (let sentence of feedbacks) {
  for (let word of sentence) {
    words.push(word);
  }
}

const wordsSet = new Set(words);
const uniqueWords = [...wordsSet];
console.log(uniqueWords);

let num_of_document_containing_term = {};
for (let word of uniqueWords) {
  let num_docs = 0;
  for (let sentence of feedbacks) {
    if (sentence.includes(word)) num_docs += 1;
  }
  num_of_document_containing_term[word] = num_docs;
}
console.log(num_of_document_containing_term);

let tf_idf = {};
for (let sentence of feedbacks) {
  for (let word of sentence) {
    // Fixed syntax:
    const tf = sentence.filter((w) => w === word).length / sentence.length;
    const idf = Math.log(
      feedbacks.length / num_of_document_containing_term[word]
    );
    const score = tf * idf;
    if (word in tf_idf) tf_idf[word] += score;
    else tf_idf[word] = score;
  }
}

console.log(tf_idf);
// Get entries and sort by score descending
let sortedEntries = Object.entries(tf_idf).sort((a, b) => b[1] - a[1]);

// Get top 5
let top5 = sortedEntries.slice(0, 10);

// Print them
console.log("Top 5 most important words:");
top5.forEach(([word, score], index) => {
  console.log(`${index + 1}. ${word}: ${score}`);
});
