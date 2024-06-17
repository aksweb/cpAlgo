solvedSchema = {
    user_id: { type: String, required: true },
    submissions=[
        submission_id: { type: String, required: true },
        problem_id: { type: String, required: true },
        language: { type: String, required: true },
        code: { type: String, required: true },
        verdict: { type: String, required: true },
        timestamp: { type: Date, default: Date.now }
    ]
}
userSchema = {
    user_id: { type: String, required: true, unique: true },
    username: { type: String, required: true },
    email: { type: String, required: true, unique: true },
    password: { type: String, required: true },
    adminRole: { type: Boolean, default: false }
}

problemSchema = {
    problem_id: { type: String, required: true, unique: true },
    author_id: { type: String, required: true },
    title: { type: String, required: true },
    description: { type: String, required: true },
    testCases: { type: String, required: true }, // Path or reference to the test cases file
    outputCases: { type: String, required: true }, // Path or reference to the output cases file
    totalSubmissions: { type: Number, default: 0 },
    correctSub: { type: Number, default: 0 },
    wrongSub: { type: Number, default: 0 }
}

submissionSchema = {
    submission_id: { type: String, required: true, unique: true },
    user_id: { type: String, required: true },
    problem_id: { type: String, required: true },
    language: { type: String, required: true },
    code: { type: String, required: true },
    verdict: { type: String, required: true },
    timestamp: { type: Date, default: Date.now }
}